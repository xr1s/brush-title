#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof str, stdin);
    int len = strlen(str);
    for (int i = 0; i != 26; ++i)
        for (int j = 0; j != len; ++j) 
            if (!isalpha(str[j])) putchar(str[j]);
            else if (isupper(str[j]))
                putchar((str[j] - 'A' + i) % 26 + 'A');
            else if (islower(str[j]))
                putchar((str[j] - 'a' + i) % 26 + 'a');
    return 0;
}

