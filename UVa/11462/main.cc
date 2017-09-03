#include <cstdio>
#include <cctype>

using namespace std;

int getint() {
    int c, r; while (!isdigit(c = getchar())); r = c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return r;
}

int buf[5]; int len;
int putint(int i) {
    do buf[len++] = i % 10; while (i /= 10);
    while (--len) putchar(buf[len] + '0');
    putchar(*buf + '0');
}

int n, i;
int count[101];

int main() {
    while (n = getint()) {
        while (n--) ++count[getint()];
        for (i = 1; !count[i]; ++i);
        putint(i);
        for (--count[i]; i <= 100; ++i)
            while (count[i]) putchar(' '), putint(i), --count[i];
        putchar('\n');
    }
    return 0;
}
