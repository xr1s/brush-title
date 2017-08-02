#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char byte;


byte enc[] = "d1b4a39d62c71e3448d820aa0021cc744e4c7e401cdb5fcb2a76912fc1926ae" \
"d3ab2bce8a64bfe9a85018980789a1d8f5bee4e7d0f091e5c05fb3e0aff14423405115d9fe4e" \
"d2d34298ec36a7f3799c8be83a4f3647de6bbe8b3cd2aa20406b39ba7b57a417ce746fb031a4" \
"7b40e";
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

bool decrypt(byte *enc, size_t len, int offset, unsigned x, unsigned m, char *msg) {
    unsigned k = 0;
    size_t mlen = 0;
    for (int i = 3; ~i; --i)
        k = k << 8 | enc[i];
    k = k * m + x;
    for (int i = 4; i + 4 < len; i += 4) {
        unsigned c = 0;
        for (int j = 3; ~j; --j)
            c = c << 8 | enc[i | j];
        unsigned dec = c ^ k;
        k = c * m + x;
        for (int j = 3; ~j; --j) {
            msg[mlen] = dec >> 24 - (j << 3);
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
    unsigned x = 0, m = 0;
    puts("key       message");
    for (unsigned xm0 = 0; xm0 != 65536; ++xm0) {
        unsigned x0 = xm0 >> 8, m0 = xm0 & 0xff;
        x &= (1 << 0) - 1; x |= x0 << 0;
        m &= (1 << 0) - 1; m |= m0 << 0;
        if (!decrypt(mid, len, 0, x, m, msg)) continue;
        for (unsigned xm1 = 0; xm1 != 65536; ++xm1) {
            unsigned x1 = xm1 >> 8, m1 = xm1 & 0xff;
            x &= (1 << 8) - 1; x |= x1 << 8;
            m &= (1 << 8) - 1; m |= m1 << 8;
            if (!decrypt(mid, len, 1, x, m, msg)) continue;
            for (unsigned xm2 = 0; xm2 != 65536; ++xm2) {
                unsigned x2 = xm2 >> 8, m2 = xm2 & 0xff;
                x &= (1 << 16) - 1; x |= x2 << 16;
                m &= (1 << 16) - 1; m |= m2 << 16;
                if (!decrypt(mid, len, 2, x, m, msg)) continue;
                for (unsigned xm3 = 0; xm3 != 65536; ++xm3) {
                    unsigned x3 = xm3 >> 8, m3 = xm3 & 0xff;
                    x &= (1 << 24) - 1; x |= x3 << 24;
                    m &= (1 << 24) - 1; m |= m3 << 24;
                    if (!decrypt(mid, len, 3, x, m, msg)) continue;
                    printf("%x  %s\n", x, msg);
                }
            }
        }
    }
    return 0;
}
