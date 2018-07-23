#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
int m, n;
int grid[505][505];

int adj[250005], gto[2000005], gnxt[2000005], e;
int dis[250005];
void add_edge(int u, int v) {
    gto[e] = v; gnxt[e] = adj[u]; adj[u] = e++;
}

int qu[250005], qh, qt;
void bfs(int s) {
    dis[0] = 1;
    for (dis[qu[qh = qt = 0] = s] = 1; qh <= qt; ++qh)
        for (int u = qu[qh], e = adj[u], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (u != v && !dis[v]) qu[++qt] = v, dis[v] = dis[u] + 1;
}

void print_neighbour(int s) {
    printf("(%d, %d):", s / n, s % n);
    for (int e = adj[s]; ~e; e = gnxt[e])
        printf(" (%d, %d)", gto[e] / n, gto[e] % n);
    putchar('\n');
}

int main() {
    scanf("%d%d", &m, &n);
    memset(adj, -1, sizeof adj);
    for (int i = 0; i != m; ++i)
        for (int j = 0; j != n; ++j) {
            while (!isdigit(grid[i][j] = getchar()));
            if (grid[i][j] -= '0') {
                if (i + grid[i][j] < m)
                    add_edge(i * n + j, (i + grid[i][j]) * n + j);
                if (i - grid[i][j] >= 0)
                    add_edge(i * n + j, (i - grid[i][j]) * n + j);
                if (j + grid[i][j] < n)
                    add_edge(i * n + j, i * n + j + grid[i][j]);
                if (j - grid[i][j] >= 0)
                    add_edge(i * n + j, i * n + j - grid[i][j]);
            }
        }
    bfs(0);
    if (dis[m * n - 1] == 0) puts("IMPOSSIBLE");
    else printf("%d\n", dis[m * n - 1] - 1);
    return 0;
}
