#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int n, m;
int adj[1005], gto[2005], gnxt[2005], e;
int qu[1005], qh, qt;
int dis[1005];
list<int> child[1005];

void add_edge(int u, int v) {
    gto[e] = v; gnxt[e] = adj[u]; adj[u] = e++;
}

void bfs(int s) {
    for (dis[qu[qh = qt = 0] = s] = 0; qh <= qt; ++qh) {
        for (int u = qu[qh], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]]) {
            if (v != s && !dis[v]) dis[v] = dis[u] + 1, qu[++qt] = v;
            if (dis[v] == dis[u] + 1) child[u].push_back(v);
        }
    }
}

int dfs(int s) {
    if (child[s].empty()) return dis[s] & 1;
    if (~dis[s] & 1) {
        bool win = false;
        for (auto chld: child[s])
            win |= dfs(chld);
        return win;
    } else {
        bool lose = true;
        for (auto chld: child[s])
            lose &= dfs(chld);
        return lose;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(adj, -1, sizeof adj);
    scanf("%d%d", &n, &m);
    for (int i = 0; i != m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        add_edge(u, v); add_edge(v, u);
    }
    bfs(1);
    puts(dfs(1) ? "Vladimir" : "Nikolay");
    return 0;
}
