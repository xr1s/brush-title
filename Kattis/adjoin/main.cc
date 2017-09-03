#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int c, l;
int adj[100005], gto[200005], gnxt[200005], e;
int qu[100005], qh, qt, dis[100005], fng = -1, sng = -1, tng = -1;
int f[100005];
int maxi;

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) {
    f[find(y)] = find(x);
}

void add_edge(int u, int v) {
    gto[e] = v; gnxt[e] = adj[u]; adj[u] = e++;
}

int bfs(int s) {
    memset(dis, 0, sizeof dis);
    for (dis[qu[qh = qt = 0] = s] = 1; qh <= qt; ++qh)
        for (int u = qu[qh], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (!dis[v]) dis[v] = dis[u] + 1, qu[++qt] = v, unite(s, v);
    return qu[qt];
}

int main() {
    scanf("%d%d", &c, &l);
    memset(adj, -1, sizeof adj);
    for (int i = 0; i != c; ++i) f[i] = i;
    for (int i = 0; i != l; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        add_edge(u, v); add_edge(v, u);
    }
    for (int i = 0; i != c; ++i)
        if (find(i) == i) {
            int f0 = bfs(i);
            int f1 = bfs(f0);
            maxi = max(maxi, dis[f1] - 1);
            if (dis[f1] >> 1 >= fng)
                tng = sng, sng = fng, fng = dis[f1] >> 1;
            else if (dis[f1] >> 1 > sng)
                tng = sng, sng = dis[f1] >> 1;
            else if (dis[f1] >> 1 > tng) tng = dis[f1] >> 1;
        }
    bool connect = true;
    for (int i = 0; i != c; ++i) connect &= find(i) == 0;
    if (connect) printf("%d\n", maxi);
    else printf("%d\n", max(maxi, fng + sng + 1 + (fng == tng)));
    return 0;
}
