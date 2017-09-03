#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int V, E;
int adj[10005], gto[400005], gnxt[400005], gw[400005], e;
int qu[10005], qh, qt, inq[10005];
int dis[10005], cnt[10005];

int add_edge(int u, int v, int w) {
    gto[e] = v; gw[e] = w; gnxt[e] = adj[u]; adj[u] = e++;
}

void bellman_ford(int s, int t) {
    memset(dis, 0x7f, sizeof dis); dis[s] = 0; cnt[s] = 1;
    for (inq[qu[qh = qt] = s] = 1; qh <= qt; inq[qu[qh++ % V]] = 0)
        for (int u = qu[qh % V], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]]) {
            if (dis[v] >= dis[u] + gw[e] && !inq[v]) inq[qu[++qt % V] = v] = 1;
            if (dis[v] > dis[u] + gw[e]) dis[v] = dis[u] + gw[e], cnt[v] = cnt[u];
            else if (dis[v] == dis[u] + gw[e]) cnt[v] += cnt[u];
        }
}


priority_queue<
    pair<int, int>,
    vector<pair<int, int> >,
    greater<pair<int, int> >
> pq;

void dijkstra(int s, int t) {
    memset(dis, 0x7f, sizeof dis); dis[s] = 0; cnt[s] = 1;
    pq.push(make_pair(dis[s], s));
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if (dis[u] != d) continue;
        for (int e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (dis[v] > dis[u] + gw[e])
                pq.push(make_pair(dis[v] = dis[u] + gw[e], v)), cnt[v] = cnt[u];
            else if (dis[v] == dis[u] + gw[e]) cnt[v] += cnt[u];
    }
}

int main() {
    memset(adj, -1, sizeof adj);
    scanf("%d%d", &V, &E);
    for (int i = 0; i != E; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    int s, t; scanf("%d%d", &s, &t);
    //bellman_ford(s, t);
    dijkstra(s, t);
    printf("%d\n", cnt[t]);
    return 0;
}
