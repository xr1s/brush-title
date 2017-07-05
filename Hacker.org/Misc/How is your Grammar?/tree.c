#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *map[] = {
    ['A'] = "is",
    ['B'] = "mm",
    ['C'] = "oo",
    ['D'] = "rgr",
    ['E'] = "ryg",
    ['F'] = "dth",
    ['G'] = "you",
    ['H'] = "esol",
    ['I'] = "ionA",
    ['J'] = "GDaBarA",
    ['K'] = "veECFHutI",
    ['L'] = "PQ",
    ['M'] = "n",
    ['N'] = "m",
    ['O'] = "oaNcho",
    ['P'] = "MO",
    ['Q'] = "NR",
    ['R'] = "sky",
    ['S'] = "JKL",
};

void preorder(char s) {
    if (isupper(s))
        for (size_t i = 0; i != strlen(map[s]); ++i)
            preorder(map[s][i]);
    if (islower(s))
        putchar(s);
}

int main() {
    preorder('S');
    return 0;
}
