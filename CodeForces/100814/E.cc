#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M;
int dp[105][105][2005];

int main() {
    for (scanf("%d", &T); T; --T) {
        memset(dp, 0xff, sizeof dp);
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++i) dp[i][0][0] = 0;
        for (int j = 1; j <= M; ++j) dp[0][j][0] = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j) {
                int X; scanf("%d", &X);
                int p2 = 0, p3 = 0;
                while (X % 2 == 0) ++p2, X /= 2;
                while (X % 3 == 0) ++p3, X /= 3;
                for (int k = 2000; k >= p3; --k) {
                    if (dp[i - 1][j][k - p3] != -1)
                        if (dp[i][j][k] < dp[i - 1][j][k - p3] + p2)
                            dp[i][j][k] = dp[i - 1][j][k - p3] + p2;
                    if (dp[i][j - 1][k - p3] != -1)
                        if (dp[i][j][k] < dp[i][j - 1][k - p3] + p2)
                            dp[i][j][k] = dp[i][j - 1][k - p3] + p2;
                }
            }
        int answer = 0;
        for (int k = 0; k <= 2000; ++k)
            answer = max(answer, min(k, dp[N][M][k]));
        printf("%d\n", answer);
    }
    return 0;
}
