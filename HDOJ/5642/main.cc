#include <cstdio>
using namespace std;

constexpr long long mod = 1000000007ll;
long long T, n;
long long king[2005] = {1, 26, 26 * 26, 26 * 26 * 26}, cur = 3;

int main() {
    for (scanf("%lld", &T); T; --T) {
        scanf("%lld", &n);
        if (cur > n) {
            printf("%lld\n", king[n]);
            continue;
        }
        for (int i = cur + 1; i <= n; ++i)
            king[i] = (king[i - 1] * 25 % mod + king[i - 2] * 25 % mod + king[i - 3] * 25 % mod) % mod;
        printf("%lld\n", king[n]);
    }
    return 0;
}
