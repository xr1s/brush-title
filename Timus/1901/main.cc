#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, s;
int v[100005];
bool vis[100005];
int stk[100005], stktop;
int ans;

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i != n; ++i) scanf("%d", &v[i]);
    sort(v, v + n, greater<int>());
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        while (v[l] + v[r] <= s && l < r) --r;
        if (l >= r) break;
        vis[l] = vis[r] = true;
        stk[stktop++] = v[r];
        stk[stktop++] = v[l];
    }
    for (int i = 0; i != n; ++i)
        if (!vis[i]) stk[stktop++] = v[i];
    for (int i = 0; i < stktop; ++i) {
        if (stk[i] + stk[i + 1] <= s) ++i;
        ++ans;
    }
    printf("%d\n%d", ans, stk[0]);
    for (int i = 1; i < stktop; ++i) printf(" %d", stk[i]);
    putchar('\n');
    return 0;
}
