#include <ctype.h>
#include <stdio.h>
int main() {
    int str[1000]; size_t len;
    char msg[1000], hex;
    while (scanf("%hhx", &hex) != EOF) str[len++] = hex;
    for (int i = 0, j; i != 103; ++i) {
        for (j = 0; j != len; ++j) {
            char chr = (str[j] - 26 + i) % 103 + 26;
            if (!isprint(chr)) break;
            else msg[j] = chr;
        }
        if (j == len) puts(msg);
    }
    return 0;
}

