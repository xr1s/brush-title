#include <stdio.h>
#include <string.h>

char str[1024];
size_t len;
char byte, count;

int main() {
    freopen("modified.txt", "r", stdin);
    while (fgets(str, sizeof str, stdin) != NULL) {
        len = strlen(str);
        byte = byte << 1 | (str[len - 3] == ' ' && str[len - 2] == ' ');
        if (!(++count & 7)) putchar(byte), byte = count = 0;
    }
    fclose(stdin);
    return 0;
}

