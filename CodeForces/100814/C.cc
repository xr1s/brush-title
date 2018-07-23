#include <cstdio>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

#define op(x) get<0>(x)
#define id(x) get<1>(x)
#define u(x) get<2>(x)
#define v(x) get<3>(x)

constexpr int maxn = 2000005;

int T, n, m;
int f[maxn];
int pre[maxn][25];
int child[maxn][2], node;
int contime[maxn];
tuple<int, int, int, int> query[maxn];

void build(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) pre[i][0] = i;
}

int find(int u) {
    if (f[u] != u) f[u] = find(f[u]);
    return f[u];
}

bool same_set(int u, int v) {
    int fu = find(u), fv = find(v);
    return fu == fv;
}

void unite(int u, int v, int time) {
    int fu = find(u), fv = find(v);
    if (fu == fv) return;
    f[fv] = f[fu] = ++n;
    pre[fu][0] = pre[fv][0] = n;
    pre[n][0] = n;
    child[n][0] = fu;
    child[n][1] = fv;
    contime[n] = time;
}

int dep[200005];
int qu[200005], qh, qt;
void bfs(int s) {
    for (dep[qu[qh = qt = 0] = s] = 1; qh <= qt; ++qh) {
        int root = qu[qh];
        if (!*child[root]) continue;
        dep[child[root][0]] = dep[child[root][1]] = dep[root] + 1;
        qu[++qt] = child[root][0];
        qu[++qt] = child[root][1];
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int d = 19; ~d; --d)
        if (dep[pre[u][d]] >= dep[v]) u = pre[u][d];
    if (u == v) return u;
    for (int d = 19; ~d; --d)
        if (pre[u][d] != pre[v][d])
            u = pre[u][d], v = pre[v][d];
    return pre[u][0];
}

int main() {
    for (scanf("%d", &T); T; --T) {
        memset(f, 0, sizeof f);
        memset(pre, 0, sizeof pre);
        memset(child, 0, sizeof child);
        memset(contime, 0, sizeof contime);
        for (int i = 1; i <= m; ++i) query[i] = {0, 0, 0, 0};
        scanf("%d%d", &n, &m);
        build(n << 1);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &op(query[i]), &u(query[i]), &v(query[i]));
            id(query[i]) = i;
        }
        sort(query + 1, query + m + 1);
        int first2 = 1;
        while (op(query[first2]) == 1 && first2 <= m) ++first2;
        for (int i = 1; i != first2; ++i)
            unite(u(query[i]), v(query[i]), id(query[i]));
        for (int i = 1; i <= n; ++i)
            if (pre[i][0] == i) bfs(i);
        for (int i = 1; i <= 20; ++i)
            for (int j = 1; j <= n; ++j)
                pre[j][i] = pre[pre[j][i - 1]][i - 1];
        for (int i = first2; i <= m; ++i) {
            if (!same_set(u(query[i]), v(query[i]))) {
                puts("-1"); continue;
            }
            int ct = contime[lca(u(query[i]), v(query[i]))];
            if (ct > id(query[i])) {
                puts("-1"); continue;
            } else printf("%d\n", ct);
        }
    }
    return 0;
}
