#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int maxN = 10005;
constexpr int maxM = 400005;

int N, M;

int adj[maxN], gto[maxM], gnxt[maxM], length[maxM], cost[maxM], e;
void add_edge(int u, int v, int d, int c) {
    gto[e] = v; length[e] = d; cost[e] = c; gnxt[e] = adj[u]; adj[u] = e++;
}

int dis[maxN], pre[maxN];
int qu[maxN], qh, qt; bool inq[maxN];
void bellman_ford(int s) {
    memset(dis, 0x3f, sizeof dis); dis[s] = 0;
    for (inq[qu[qh = qt = 0] = s] = 1; qh <= qt; inq[qu[qh++ % N]] = 0)
        for (int u = qu[qh % N], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (dis[v] > dis[u] + length[e]) {
                dis[v] = dis[u] + length[e];
                pre[v] = cost[e];
                if (!inq[v]) inq[qu[++qt % N] = v] = 1;
            } else if (dis[v] == dis[u] + length[e]) {
                pre[v] = min(pre[v], cost[e]);
            }
}

int main() {
    while (~scanf("%d%d", &N, &M) && (N || M)) {
        memset(adj, -1, sizeof adj);
        for (int i = 0; i != M; ++i) {
            int u, v, d, c; scanf("%d%d%d%d", &u, &v, &d, &c);
            add_edge(u, v, d, c); add_edge(v, u, d, c);
        }
        bellman_ford(1);
        long long ans = 0;
        for (int i = 1; i <= N; ++i) ans += pre[i];
        printf("%lld\n", ans);
    }
    return 0;
}
