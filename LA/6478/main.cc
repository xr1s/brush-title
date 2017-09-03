#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, DNA[14], cnt[10];

bool dfs(int num) {
    if (num == 4) return true;
    for (int i = 1; i != 8; ++i)
        if (cnt[i] && cnt[i + 1] && cnt[i + 2]) {
            --cnt[i]; --cnt[i + 1]; --cnt[i + 2];
            if (dfs(num + 1)) return true;
            ++cnt[i]; ++cnt[i + 1]; ++cnt[i + 2];
        }
    for (int i = 1; i != 10; ++i)
        if (cnt[i] >= 3) {
            cnt[i] -= 3;
            if (dfs(num + 1)) return true;
            cnt[i] += 3;
        }
    return false;
}

int main() {
    for (scanf("%d", &N); N; --N) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i != 14; ++i) {
            scanf("%d", &DNA[i]);
            ++cnt[DNA[i]];
        }
        bool vuln = false;
        for (int pair = 1; pair != 10 && !vuln; ++pair)
            if (cnt[pair] >= 2) {
                cnt[pair] -= 2;
                vuln |= dfs(0);
                cnt[pair] += 2;
            }
        puts(vuln ? "Vulnerable" : "Immune");
    }
    return 0;
}
