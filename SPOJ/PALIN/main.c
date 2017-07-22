#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int t;
char n[1000005];

int main() {
    for (scanf("%d", &t); t; --t) {
        scanf("%s", n + 1); *n = 0;
        size_t len = strlen(n + 1);
        size_t half = (len + 1) >> 1;
        char *lm = n + half, *l = lm;
        char *rm = n + 1 + len - half, *r = rm;
        while (l != n && *l == *r) --l, ++r;
        if (l == n || *l < *r) {
            bool carry = true;
            for (char *d = lm; carry; --d)
                if ((carry = ++*d == ':')) *d = '0';
            if (*n) *n = '1', n[len + 3] = '\0', --lm;
        }
        while (lm >= n) *rm++ = *lm--;
        puts(n + !*n);
    }
    return 0;
}
