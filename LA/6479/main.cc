#include <cstdio>
#include <cstring>

using namespace std;

int N, W, H, I, X, Y;
char map[105][105];
bool vis[105][105];

bool ismap(char c) {
    return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'X';
}

void spread(int h, int w) {
    if (map[h][w] == 'X') return;
    if  (map[h][w] == 'D' && !vis[h][w]) {
        vis[h][w] = true;
        if (h + 1 != H)  spread(h + 1, w);
        if (h - 1 != -1) spread(h - 1, w);
        if (w + 1 != W)  spread(h, w + 1);
        if (w - 1 != -1) spread(h, w - 1);
        return;
    }
    if ('A' <= map[h][w] && map[h][w] <= 'C') ++map[h][w];
}

void print_map() {
    for (int h = 0; h != H; ++h) {
        for (int w = 0; w != W; ++w)
            putchar(map[h][w]);
        putchar('\n');
    }
    putchar('\n');
}

int main() {
    for (scanf("%d", &N); N; --N) {
        scanf("%d%d", &W, &H);
        for (int h = 0; h != H; ++h)
            for (int w = 0; w != W; ++w)
                while (!ismap(map[h][w] = getchar()));
        for (scanf("%d", &I); I; --I) {
            scanf("%d%d", &X, &Y);
            memset(vis, false, sizeof vis);
            spread(Y, X);
        }
        for (int h = 0; h != H; ++h) {
            for (int w = 0; w != W; ++w)
                putchar(map[h][w]);
            putchar('\n');
        }
    }
    return 0;
}
