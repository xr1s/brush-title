#include <cstdio>

using namespace std;

int T, H, W, N;

int main() {
#ifndef LOCAL
    freopen("figure.in", "r", stdin);
    freopen("figure.out", "w", stdout);
#endif
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d%d", &H, &W, &N);
        if (H < 2 || W < 2 || N > (H - 2) * (W - 2) + 1 >> 1) {
            puts("Impossible\n");
            continue;
        }
        for (int i = 0; i != W; ++i) putchar('.');
        putchar('\n');
        for (int i = 2; i < H; ++i) {
            putchar('.');
            for (int j = 2; j < W; ++j)
                putchar((j ^ i) & 1 || --N < 0 ? '.' : '#');
            putchar('.');
            putchar('\n');
        }
        for (int i = 0; i < W; ++i) putchar('.');
        putchar('\n');
        putchar('\n');
    }
    return 0;
}
