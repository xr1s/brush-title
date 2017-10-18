#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct trie {
    struct trie *next[26];
    bool end;
};

void trie_insert(struct trie *root, char *str) {
    for (size_t len = strlen(str); len; --len) {
        if (root->next[*str - 'a'] == NULL) {
            root->next[*str - 'a'] = malloc(sizeof(struct trie));
            memset(root->next[*str - 'a'], 0x00, sizeof(struct trie));
        }
        root = root->next[*str++ - 'a'];
    }
    root->end = true;
}

bool wechall_lettergrid_validate(char *str) {
    char *it = str;
    for (; *it != '\0'; ++it)
        if (!islower(*it)) return false;
    return it - str >= 6;
}

struct trie *trie_dictionary(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return NULL;
    int sz = lseek(fd, 0, SEEK_END);
    if (sz == -1) return NULL;
    char *bf = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    struct trie *dict = malloc(sizeof(struct trie));
    char *tk = strtok(bf, "\r\n");
    while (tk != NULL) {
        if (wechall_lettergrid_validate(tk)) {
            trie_insert(dict, tk);
        }
        tk = strtok(NULL, "\r\n");
    }
    return dict;
}

bool trie_begin_with(struct trie *root, char *str) {
    for (; *str; ++str) {
        if (!islower(*str)) return false;
        if (!root->next[*str - 'a']) return false;
        root = root->next[*str - 'a'];
    }
    return true;
}

bool trie_check(struct trie *root, char *str) {
    for (; *str; ++str) {
        if (!islower(*str)) return false;
        if (!root->next[*str - 'a']) return false;
        root = root->next[*str - 'a'];
    }
    return root->end;
}

char *readline() {
    size_t xlen = 8, len = 0;
    char *line = calloc(xlen, sizeof *line);
    fgets(line, xlen, stdin);
    if (*line == '\0') {
        free(line);
        return NULL;
    }
    while (line[xlen - 2] != '\0') {
        len = xlen - 1, xlen <<= 1;
        char *replace = realloc(line, xlen);
        if (replace == NULL) {
            free(line); len = 0;
            return NULL;
        }
        line = replace;
        fgets(line + len, xlen - len, stdin);
    }
    len += strlen(line + len);
    if (line[len - 1] == '\n') {
        line = realloc(line, len);
        line[--len] = '\0';
    } else line = realloc(line, len + 1);
    return line;
}

char **readgrid(size_t *row, size_t *col) {
    size_t xrow = 8;
    char **grid = malloc(xrow * sizeof *grid);
    *grid = readline(col);
    if (*grid == NULL) {
        free(grid);
        *row = *col = 0;
        return NULL;
    }
    *col = strlen(*grid);
    *row = 0;
    while (grid[++*row] = readline()) {
        size_t length = strlen(grid[*row]);
        if (length != *col) {
            while (length--)
                ungetc(grid[*row][length], stdin);
            free(grid[*row]);
            break;
        }
        if (*row == xrow) {
            xrow <<= 1;
            char **replace = realloc(grid, xrow * sizeof *grid);
            if (replace == NULL) {
                while (*row)
                    free(grid[(*row)--]);
                free(grid);
                *row = *col = 0;
                return NULL;
            }
            grid = replace;
        }
    }
    return realloc(grid, *row * sizeof *grid);
}

bool ingrid(int x, int y, int row, int col) {
    return 0 <= x && x < row && 0 <= y && y < col;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "Usage: %s dictionary\n", *argv);
        return EXIT_FAILURE;
    }
    struct trie *dict = trie_dictionary(argv[1]);
    if (dict == NULL) {
        perror(strerror(errno));
        return EXIT_FAILURE;
    }

    size_t row, col;
    char **grid = readgrid(&row, &col);

    bool **highlight = malloc(row * sizeof *highlight);
    for (int i = 0; i != row; ++i)
        highlight[i] = calloc(col, sizeof **highlight);

    const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int maxlen = row > col ? row : col;

    char *str = malloc(maxlen + 1);
    char answer[1024] = {0};
    for (int id = 0; id != row * col; ++id) {
        int r = id / col, c = id % col;
        *str = grid[r][c];
        for (int d = 0; d != 8; ++d) {
            size_t len = 1, x = r, y = c;
            memset(str + 1, 0x00, maxlen);
            while (ingrid(x += dx[d], y += dy[d], row, col)) {
                str[len++] = grid[x][y];
                if (!trie_begin_with(dict, str)) break;
                if (trie_check(dict, str)) {
                    strcat(answer, str);
                    int tx = x, ty = y;
                    for (int i = len; i; --i) {
                        highlight[tx][ty] = true;
                        tx -= dx[d], ty -= dy[d];
                    }
                }
            }
        }
    }
    puts(answer);
    puts("");
    for (int i = 0; i != row; ++i) {
        for (int j = 0; j != col; ++j)
            if (!highlight[i][j]) putchar(grid[i][j]);
            else printf("\033[1m%c\033[0m", grid[i][j]);
        putchar('\n');
    }
    return EXIT_SUCCESS;
}
