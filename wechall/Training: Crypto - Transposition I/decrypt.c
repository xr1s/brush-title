#include <stdio.h>
#include <string.h>
int main() {
    char cipher[1000] = {0};
    fgets(cipher, sizeof cipher, stdin);
    size_t len = strlen(cipher);
    for (size_t i = 0; i != len; ++i)
        putchar(cipher[i ^ 1]);
    putchar('\n');
    return 0;
}

