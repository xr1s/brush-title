#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int N, year, d;
long long money;
int b[15];
long long in[15];
long long dp[50000];

int main() {
    for (scanf("%d", &N); N; --N) {
        memset(dp, 0, sizeof dp);
        scanf("%lld%d%d", &money, &year, &d);
        for (int i = 0; i != d; ++i) {
            scanf("%d%lld", &b[i], &in[i]);
            if ((b[i] /= 1000) >= 50000) --i, --d;
        }
        for (int i = 0; i != d; ++i)
            for (int j = b[i]; j != 50000; ++j)
                dp[j] = max(dp[j], dp[j - b[i]] + in[i]);
        for (int i = 0; i != year; ++i)
            money += dp[money / 1000];
        printf("%lld\n", money);
    }
    return 0;
}
