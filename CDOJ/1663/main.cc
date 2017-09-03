#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int T, n;
int f[1005];
bool vis[1005];
int s[1005];

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

int main() {
    for (scanf("%d", &T); T; --T) {
        memset(vis, false, sizeof vis);
        memset(s, 0, sizeof s);
        set<int> count;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
        for (int i = 1; i <= n; ++i)
            for (int x = f[i]; !vis[x]; x = f[x])
                s[x] = i, vis[x] = true;
        for (int i = 1; i <= n; ++i) count.insert(s[i]);
        printf("%lu\n", count.size());
    }
    return 0;
}
