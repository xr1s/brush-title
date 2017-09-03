#include <cstdio>
#include <cstring>

using namespace std;

int T, n, p;
long long a, b;
long long remain[2][205];

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%lld%lld%d%d", &a, &b, &n, &p);
        long long answer = 0;
        memset(*remain, 0, p * sizeof **remain); **remain = 1;
        for (int i = 0, cur = 0; i != n; ++i) {
            ((cur *= 10) += (a *= 10) / b) %= p, a %= b;
            answer += remain[i & 1][cur]++;
            memset(remain[i & 1 ^ 1], 0, p * sizeof **remain);
            for (int j = 0; j != p; ++j)
                remain[i & 1 ^ 1][j * 10 % p] += remain[i & 1][j];
        }
        printf("%lld\n", answer);
    }
    return 0;
}
