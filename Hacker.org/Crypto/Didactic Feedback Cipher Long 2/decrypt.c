#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char byte;


byte enc[] = "5499fa991ee7d8da5df0b78b1cb0c18c10f09fc54bb7fdae7fcb95ace494fba" \
"e8f5d90a3c766fdd7b7399eccbf4af592f35c9dc2272be2a45e788697520febd8468c808c2e5" \
"50ac92b4d28b74c16678933df0bec67a967780ffa0ce344cd2a9a2dc208dc35c26a9d658b0fd" \
"70d00648246c90cf828d72a794ea94be51bbc6995478505d37b1a6b8daf7408dbef7d7f9f764" \
"71cc6ef1076b46c911aa7e75a7ed389630c8df32b7fcb697c1e89091c30be736a4cbfe27339b" \
"b9a2a52a280";
byte mid[1024];
byte msg[1024];

int unhex(byte c) {
    switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            c = c - '0'; break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            c = c - 'a' + 10; break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            c = c - 'A' + 10; break;
    }
    return c;
}

void unhexlify(char src[], char dst[]) {
    while (*src) {
        *dst = *dst << 4 | unhex(*src++);
        *dst = *dst << 4 | unhex(*src++);
        ++dst;
    }
    *dst = 0;
}

bool decrypt(byte *enc, size_t len, int offset, unsigned x, char *msg) {
    unsigned k = 0;
    size_t mlen = 0;
    for (int i = 3; ~i; --i)
        k = k << 8 | enc[i];
    k += x;
    for (int i = 4; i + 4 < len; i += 4) {
        unsigned c = 0;
        for (int j = 3; ~j; --j)
            c = c << 8 | enc[i | j];
        unsigned m = c ^ k;
        k = c + x;
        for (int j = 3; ~j; --j) {
            msg[mlen] = m >> 24 - (j << 3);
            if ((mlen++ & 3) == offset)
                if (!isprint(msg[mlen - 1])) return false;
        }
    }
    msg[mlen] = '\0';
    return true;
}

int main() {
    int len = strlen(enc) >> 1;
    unhexlify(enc, mid);
    unsigned x = 0;
    puts("key       message");
    for (unsigned x0 = 0; x0 != 256; ++x0) {
        x &= (1 << 0) - 1; x |= x0 << 0;
        if (!decrypt(mid, len, 0, x, msg)) continue;
        for (unsigned x1 = 0; x1 != 256; ++x1) {
            x &= (1 << 8) - 1; x |= x1 << 8;
            if (!decrypt(mid, len, 1, x, msg)) continue;
            for (unsigned x2 = 0; x2 != 256; ++x2) {
                x &= (1 << 16) - 1; x |= x2 << 16;
                if (!decrypt(mid, len, 2, x, msg)) continue;
                for (unsigned x3 = 0; x3 != 256; ++x3) {
                    x &= (1 << 24) - 1; x |= x3 << 24;
                    if (!decrypt(mid, len, 3, x, msg)) continue;
                    printf("%x  %s\n", x, msg);
                }
            }
        }
    }
    return 0;
}
