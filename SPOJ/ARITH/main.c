#include <stdio.h>
#include <string.h>
#include <ctype.h>

int t;
char expr[1005];
char va[1005][1005];
char result[1005];
size_t rlen;
size_t vc, vl[505];

size_t max(size_t lhs, size_t rhs) {
    return lhs > rhs ? lhs : rhs;
}

void addition(const char *ls, char *lt, const char *rs, char *rt) {
    char *res = result;
    while (lt != ls && rt != rs)
        if ((*res++ += *--lt + *--rt - '0') > '9') res[-1] -= 10, *res = 1;
    while (lt != ls) if ((*res++ += *--lt) == ':') res[-1] = '0', *res = 1;
    while (rt != rs) if ((*res++ += *--rt) == ':') res[-1] = '0', *res = 1;
    if (*res) *res++ = '1';
    *res = '\0';
    rlen = res - result;
}

void subtraction(const char *ls, char *lt, const char *rs, char *rt) {
    char *res = result;
    while (lt != ls && rt != rs)
        if ((*res++ += '0' + *--lt - *--rt) < '0') res[-1] += 10, --*res;
    while (lt != ls) if ((*res++ += *--lt) == '/') res[-1] = '9', --*res;
    while (res != result + 1 && res[-1] == '0') --res;
    *res = '\0';
    rlen = res - result;
}

void multiplication(const char *ls, char *lt, const char *rs, char *rt) {
    for (char *r = rt - 1; r >= rs; --r) {
        char *v = va[vc++];
        for (char *l = lt - 1; l >= ls; --l, ++v)
            if ((*v += (*l - '0') * (*r - '0')) > 9)
                v[1] = *v / 10, *v %= 10;
        v += !!*v;
        while (v != va[vc - 1] + 1 && !v[-1]) --v;
        vl[vc - 1] = v - va[vc - 1];
    }
    char *res = result;
    for (size_t i = 1; i != vc + vl[vc - 1]; ++i, *res++ += '0')
        for (size_t j = 0; j != i; ++j)
            if ((*res += va[j][i - j - 1]) > 9)
                if (*res -= 10, ++res[1] == 10)
                    if (res[1] = 0, ++res[2] == 10)
                        res[2] = 0, ++res[3];
    rlen = vc + vl[vc - 1] - 1;
    if (result[rlen]) result[rlen++] += '0';
    if (result[rlen]) result[rlen++] += '0';
    for (size_t i = 0; i != vc; ++i)
        for (char *v = va[i] + vl[i]; v != va[i]; *--v += '0');
}

void initialize() {
    memset(va, 0, sizeof va);
    memset(vl, 0, sizeof vl);
    memset(result, 0, sizeof result);
    vc = rlen = 0;
}

int main() {
    for (scanf("%d", &t); t; --t) {
        initialize();
        scanf("%s", expr);
        size_t exlen = strlen(expr);
        char *op = expr;
        while (isdigit(*op)) ++op;
        switch (*op) {
            case '+': addition(expr, op, op + 1, expr + exlen); break;
            case '-': subtraction(expr, op, op + 1, expr + exlen); break;
            case '*': multiplication(expr, op, op + 1, expr + exlen); break;
        }
        // head
        size_t maxlen = max(max(op - expr, expr + exlen - op), rlen);
        for (size_t i = op - expr; i != maxlen; ++i) putchar(' ');
        for (char *d = expr; d != op; putchar(*d++));
        putchar('\n');
        for (size_t i = expr + exlen - op; i != maxlen; ++i) putchar(' ');
        for (char *d = op; d != expr + exlen; putchar(*d++));
        putchar('\n');
        size_t delilen = max(expr + exlen - op, vc > 1 ? vl[0] : rlen);
        for (size_t i = delilen; i != maxlen; ++i) putchar(' ');
        for (size_t i = 0; i != delilen; ++i) putchar('-');
        putchar('\n');
        // body
        if (vc > 1) {
            for (size_t i = 0; i != vc; ++i) {
                for (size_t j = vl[i] + i; j != maxlen; ++j) putchar(' ');
                for (char *d = va[i] + vl[i]; d != va[i]; putchar(*--d));
                putchar('\n');
            }
            for (size_t i = rlen; i != maxlen; ++i) putchar(' ');
            for (size_t i = 0; i != rlen; ++i) putchar('-');
            putchar('\n');
        }
        // tail
        for (size_t i = rlen; i != maxlen; ++i) putchar(' ');
        for (char *d = result + rlen; d != result; putchar(*--d));
        putchar('\n');
        putchar('\n');
    }
    return 0;
}
