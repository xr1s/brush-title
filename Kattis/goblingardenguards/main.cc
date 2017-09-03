#include <cstdio>
#include <bitset>
using namespace std;

int n, m, x[100005], y[100005];
bitset<10005> garden[10005];
int answer;

inline int sqr(int x) {
    return x * x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (scanf("%d", &m); m; --m) {
        int x, y, r; scanf("%d%d%d", &x, &y, &r);
        for (int i = max(x - r, 0); i <= min(x + r, 10000); ++i)
            for (int j = max(y - r, 0); j <= min(y + r, 10000); ++j)
                if (sqr(x - i) + sqr(y - j) <= sqr(r)) garden[i][j] = true;
    }
    for (int i = 0; i != n; ++i)
        if (!garden[x[i]][y[i]]) ++answer;
    printf("%d\n", answer);
    return 0;
}
