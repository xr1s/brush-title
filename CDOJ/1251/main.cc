#include <cstdio>
using namespace std;

int T, n, s;

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &n, &s);
        if (!n || !s && n > 1 || n * 9 < s) {
            puts("-1 -1");
            continue;
        }
        if (n == 1 || s == 0) {
            if (s > 9) puts("-1 -1");
            else printf("%d %d\n", s, s);
            continue;
        }
        int rem = (s - 1) % 9, log = (s - 1) / 9;
        if (log + 1 == n) {
            putchar(rem + 1 + '0');
            for (int i = 0; i != log; ++i) putchar('9');
        } else {
            putchar('1');
            for (int i = log; i < n - 2; ++i) putchar('0');
            putchar(rem + '0');
            for (int i = 0; i != log; ++i) putchar('9');
        }
        putchar(' ');
        while (s > 9) putchar('9'), s -= 9, --n;
        if (s) putchar(s + '0'), --n;
        for (int i = 0; i != n; ++i) putchar('0');
        putchar('\n');
    }
    return 0;
}
