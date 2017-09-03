#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int P, K, n;
double L, R;
double step[2][2010][2010];
#define s(i, x, y) step[i][(x) + 1005][(y) + 1005]

int main() {
    for (scanf("%d", &P); P; --P) {
        memset(step, 0, sizeof step); s(0, 0, 0) = 1;
        scanf("%d%d%lf%lf", &K, &n, &L, &R);
        double M = 1 - L - R;
        for (int i = 1; i <= n; ++i) {
            int pre = i & 1 ^ 1;
            for (int j = -i; j <= i; ++j) {
                if (j >= 0) s(i & 1, j, j) = s(pre, j, j) * M
                                             + s(pre, j - 1, j) * R
                                             + s(pre, j - 1, j - 1) * R;
                for (int k = max(0, j + 1); k <= i; ++k)
                    s(i & 1, j, k) = s(pre, j, k) * M
                                 + s(pre, j - 1, k) * R
                                 + s(pre, j + 1, k) * L;
            }
        }
        double sum = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = -n; j <= i; ++j)
                sum += s(n & 1, j, i) * i;
        printf("%d %.4lf\n", K, sum);
    }
    return 0;
}
