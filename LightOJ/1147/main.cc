#include <cctype>
#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

int T, n, w;
bitset<100005> bs[105];

int getint() {
    char c; while (!isdigit(c = getchar())); int r = c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return r;
}

int main() {
    T = getint();
    for (int ks = 1; ks <= T; ++ks) {
        for (int i = 1; i <= n; ++i) bs[i].reset();
        bs[0].set(0);
        n = getint();
        int sum = 0, diff = ~0u >> 1, lhs, rhs;
        for (int i = 1; i <= n; ++i) {
            sum += w = getint();
            for (int j = i; j; --j)
                bs[j] |= bs[j - 1] << w;
        }
        for (int j = 0; j <= sum; ++j)
            if (bs[n >> 1][j] && abs(sum - j * 2) < diff)
                diff = abs(sum - j * 2), lhs = j, rhs = sum - j;
        printf("Case %d: %d %d\n", ks, min(lhs, rhs), max(lhs, rhs));
    }
    return 0;
}
