#include <stdio.h>

int main() {
    char bcd[5];
    while (scanf("%s", bcd) != EOF) {
        int number = 0;
        for (size_t i = 0; i != 4; ++i)
            (number <<= 1) |= bcd[i] == '1';
        printf("%d", number);
    }
    return 0;
}

