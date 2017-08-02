#include <cstdio>
#include <cstring>

using namespace std;

int N;
char enc[5001];
size_t len;
unsigned long long dp[5001];

bool check(char l, char r = '\0') {
    if (r == '\0') return '0' < l && l <= '9';
    if (l <= '0' || '2' < l) return false;
    if (r < '0' || '9' < r) return false;
    return l != '2' || '0' <= r && r <= '6';
}

int main() {
    while (~scanf("%s", enc)) {
        if (!strcmp(enc, "0")) break;
        memset(dp, 0, sizeof dp);
        len = strlen(enc);
        dp[0] = 1;
        dp[1] = '0' < enc[0] && enc[0] <= '9';
        for (int i = 2; i <= len; ++i) {
            if (check(enc[i - 1])) dp[i] += dp[i - 1];
            if (check(enc[i - 2], enc[i - 1])) dp[i] += dp[i - 2];
        }
        printf("%llu\n", dp[len]);
    }
    return 0;
}
