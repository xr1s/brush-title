#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte cipher[] = "382d817119a18844865d880255a8221d90601ad164e8a8e1dd8a48f45846" \
"152255f839e09ab176154244faa95513d16e5e314078a97fdb8bb6da8d5615225695225674a4" \
"001a9177fb112277c45e17f85753c504d7187ed3cd43b107803827e09502559bf164292affe8" \
"aaa8e88ac898f9447119a188448692070056a2628864e6d7105edc5866b9b9b6ebcad6dc3982" \
"952a7674a62015025695225674a400d8715efb112277c45edb799f9728355c586f95b002e8aa" \
"815b83df3704571b99b6346426bd9862920721751857cb38f69bb3dee18ce1793bc857e27f74" \
"a400dd8a48d971bc15d07f521921b80948a86a8eb70457d1138279a796b8fbc43d9801e8ead6" \
"69c8dcb10781788b5fe91097bad104d9ab952190a15ae706b50477b8dbe4d3cd437119c12842" \
"a42190e1a868aeb76446588d52b1078057e27cf7c65fa84aae5b8bbf6b88c19b9176a94a8eb7" \
"045778513712f1679b655d9c0255e88ac889b882b8f104711ba1dbabd7120520e188e1952256" \
"55a802c184a0282affa86a8eb70457120542f7187658515f154244548a4212074278e7c6d3cd" \
"4595283e3d9a61d8ad56ba294878c5e69502551bf162487886280aff7b3309";
byte enc[1024];
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

byte hex(int d) {
    switch (d) {
        case 0: case 1: case 2: case 3: case 4:
        case 5: case 6: case 7: case 8: case 9:
            d = d + '0'; break;
        case 10: case 11: case 12: case 13: case 14: case 15:
            d = d + 'a' - 10; break;
    }
    return d;
}

size_t decrypt(const byte enc[], const size_t len, byte key[], byte msg[]) {
//    if (len % 3) return 0;
    msg[len] = '\0';
    for (int i = 0; i * 3 != len; ++i) {
        int eggs = 0;
        for (int j = 0; j != 3; ++j)
            eggs = eggs << 8 | enc[i * 3 + j];
        for (int j = 0; j != 3; ++j) {
            eggs = eggs >> 7 | eggs << 17;
            eggs &= (1 << 24) - 1;
            eggs ^= key[eggs & 3] << 8;
        }
        for (int j = 2; ~j; eggs >>= 8, --j)
            msg[i * 3 + j] = eggs & 0xff;
    }
    return len;
}

byte *unhexlify(byte src[], byte dst[]) {
    byte *result = dst;
    while (*src) {
        *dst = *dst << 4 | unhex(*src++);
        *dst = *dst << 4 | unhex(*src++);
        ++dst;
    }
    *dst = '\0';
    return result;
}

bool isprintable(byte *s, byte *t) {
    for (; s != t; ++s)
        if (*s < 0x20 || *s > 0x7f) return false;
    return true;
}

void progress_bar(unsigned long long current, unsigned long long total) {
    static const char *block[] = { " ", "▏", "▎", "▍", "▌", "▋", "▊", "▉" };
    for (int i = current * 72 / total; i; --i) printf("█");
    printf("%s", block[current * 576 / total & 7]);
    for (int i = current * 72 / total; i != 72; ++i) putchar(' ');
    printf("% 5.2lf%%\r", 100. * current / total);
    fflush(stdout);
}

int main() {
    byte key[4];
    unhexlify(cipher, enc);
    size_t len = strlen(cipher) >> 1;
    for (int k0 = 0; k0 != 256; ++k0)
        for (int k1 = 0; k1 != 256; ++k1)
            for (int k2 = 0; k2 != 256; ++k2)
                for (int k3 = 0; k3 != 256; ++k3) {
                    key[0] = k0; key[1] = k1;
                    key[2] = k2; key[3] = k3;
                    decrypt(enc, len, key, msg);
                    if (isprintable(msg, msg + len)) {
                        printf("\r%80s\r", "");
                        for (int i = 0; i != 4; ++i)
                            printf("%02x", key[i]);
                        printf("  %s\n", msg);
                    }
                    unsigned long long current = 0;
                    for (int i = 0; i != 4; ++i)
                        current = current << 8 | key[i];
                    progress_bar(current, 4294967296ull);
                }
    return 0;
}
