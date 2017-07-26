#include <ctype.h>
#include <string.h>
#include <stdio.h>

const char *map[] = {
    ['1'] = " ",    ['2'] = "abc",  ['3'] = "def",
    ['4'] = "ghi",  ['5'] = "jkl",  ['6'] = "mno",
    ['7'] = "pqrs", ['8'] = "tuv",  ['9'] = "wxyz",
};

int main() {
    int n = 1;
    for (char p = getchar(), c = getchar(); isdigit(c = getchar()); ++n, p = c)
        if (p != c || n == strlen(map[p])) putchar(map[p][n - 1]), n = 0;
    return 0;
}
