#include <stdio.h>
#include <string.h>
#include <ctype.h>

int roman2decimal(char *s, char *t) {
    int decimal = 0;
    for (char *r = s; r != t;)
        switch (toupper(*r++)) {
        case 'I':
            switch (*r) {
            case 'V': decimal += 4; ++r; break;
            case 'X': decimal += 9; ++r; break;
            default:  decimal += 1; break;
            }
            break;
        case 'V': decimal += 5; break;
        case 'X':
            switch (*r) {
            case 'L': decimal += 40; ++r; break;
            case 'C': decimal += 90; ++r; break;
            default:  decimal += 10; break;
            }
            break;
        case 'L': decimal += 50; break;
        case 'C':
            switch (*r) {
            case 'D': decimal += 400; ++r; break;
            case 'M': decimal += 900; ++r; break;
            default:  decimal += 100; break;
            }
        break;
        case 'D': decimal += 500;  ++r; break;
        case 'M': decimal += 1000; ++r; break;
        default: return -1;
        }
    return decimal;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char roman[1024];
        while (scanf("%s", roman) != EOF) {
            char *l = roman, *r = roman;
            while (*r) *r = toupper(*r), ++r;
            putchar(roman2decimal(l, r));
            putchar('\n');
        }
    } else {
        for (int i = 1; i != argc; ++i) {
            char *l = argv[i], *r = argv[i];
            while (*r) *r = toupper(*r), ++r;
            putchar(roman2decimal(l, r));
        }
    }
    return 0;
}
