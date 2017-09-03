#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int adj[200005], gto[400005], gnxt[400005], e;
bool mv[400005];
int qu[200005], qh, qt;
bool vs[200005];
int rev[200005];
int mini = ~0u >> 1;

void add_edge(int s, int t, bool move) {
    gto[e] = t; mv[e] = move; gnxt[e] = adj[s]; adj[s] = e++;
}

int bfs(int s) {
    int reverse = 0;
    for (vs[qu[qh = qt = 0] = s] = 1; qh <= qt; ++qh)
        for (int u = qu[qh], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (!vs[v]) reverse += !mv[e], vs[qu[++qt] = v] = 1;
    return reverse;
}

void dfs(int s, int pre) {
    for (int e = adj[s], v = gto[e]; ~e; v = gto[e = gnxt[e]])
        if (gto[e] != pre) {
            rev[v] = rev[s];
            if (mv[e]) ++rev[v]; else --rev[v];
            dfs(v, s);
        }
}

int main() {
    memset(adj, -1, sizeof adj);
    scanf("%d", &n);
    for (int i = 1; i != n; ++i) {
        int s, t; scanf("%d%d", &s, &t);
        add_edge(s, t, 1); add_edge(t, s, 0);
    }
    rev[1] = bfs(1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        mini = min(mini, rev[i]);
    printf("%d\n", mini);
    int cur = 1;
    for (; cur <= n; ++cur)
        if (rev[cur] == mini) {
            printf("%d", cur);
            break;
        }
    for (++cur; cur <= n; ++cur)
        if (rev[cur] == mini) printf(" %d", cur);
    putchar('\n');
    return 0;
}
