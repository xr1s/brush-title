#include <cstdio>
#include <cstring>

using namespace std;

int N;
char encode[105];
size_t len;
unsigned long long dp[105];
//long long answer;

bool check(char l, char r = '\0') {
    if (r == '\0') return '0' < l && l <= '9';
    if (l <= '0' || '2' < l) return false;
    if (r < '0' || '9' < r) return false;
    return l != '2' || '0' <= r && r <= '6';
}

int main() {
    scanf("%d", &N);
    for (int kase = 1; kase <= N; ++kase) {
        memset(dp, 0, sizeof dp);
        scanf("%s", encode);
        len = strlen(encode);
        dp[0] = 1;
        dp[1] = '0' < encode[0] && encode[0] <= '9';
        for (int i = 2; i <= len; ++i) {
            if (check(encode[i - 1])) dp[i] += dp[i - 1];
            if (check(encode[i - 2], encode[i - 1])) dp[i] += dp[i - 2];
        }
        printf("Case #%d: %llu\n", kase, dp[len]);
    }
    return 0;
}
