#include <cstdio>
#include <algorithm>
using namespace std;

int N, k;
int num[500005][2], dp[500005][2];

int main() {
    scanf("%d%d", &N, &k);
    for (int i = 0; i != N; ++i) {
        int x; scanf("%d", &x);
        ++num[i % k][x < 0];
    }
    dp[0][0] = num[0][0]; dp[0][1] = num[0][1];
    for (int i = 1; i != k; ++i) {
        dp[i][0] = min(dp[i - 1][0] + num[i][1], dp[i - 1][1] + num[i][0]);
        dp[i][1] = min(dp[i - 1][0] + num[i][0], dp[i - 1][1] + num[i][1]);
    }
    printf("%d\n", dp[k - 1][1]);
    return 0;
}
