#include <ctype.h>
#include <stdio.h>
#include <string.h>

int t;
char expression[405];
size_t length;

void dfs(char *l, char *r) {
    size_t top = 0;
    char *s = NULL, *op = NULL;
    for (char *p = l; p != r; ++p)
        if (isalpha(*p)) {
            if (!top) putchar(*p);
        } else if (*p == '(') {
            if (!top++) s = p + 1;
        } else if (*p == ')') {
            if (!--top) dfs(s, p);
        } else if (!top) op = p;
    if (op) putchar(*op);
}

int main() {
    for (scanf("%d", &t); t; --t) {
        scanf("%s", expression);
        length = strlen(expression);
        dfs(expression, expression + length);
        putchar('\n');
    }
    return 0;
}
