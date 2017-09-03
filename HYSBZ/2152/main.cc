#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int adj[200005], gto[400005], gnxt[400005], gw[400005], e;
bool isroot[200005];
int size[200005];

void add_edge(int x, int y, int w) {
    gto[e] = y; gw[e] = w; gnxt[e] = adj[x]; adj[x] = e++;
}

int getsize(int node, int pre) {
    size[node] = 1;
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (!isroot[gto[e]] && gto[e] != pre)
            size[node] += getsize(gto[e], node);
    return size[node];
}

void getroot(int node, int pre, int subsz, int &root, int &rootsz) {
    int maxsz = subsz - size[node];
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (!isroot[gto[e]] && gto[e] != pre) {
            getroot(gto[e], node, subsz, root, rootsz);
            maxsz = max(maxsz, size[gto[e]]);
        }
    if (maxsz < rootsz) root = node, rootsz = maxsz;
}

int cnt[3];
void getdis(int node, int pre, int init) {
    ++cnt[init % 3];
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (gto[e] != pre && !isroot[gto[e]])
            getdis(gto[e], node, (init + gw[e]) % 3);
}

inline int calc(int node, int pre, int init) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    getdis(node, pre, init);
    return cnt[0] * cnt[0] + cnt[1] * cnt[2] * 2;
}

int dfs(int node) {
    int subsz = getsize(node, 0);
    int root, rootsz = ~0u >> 1;
    getroot(node, 0, subsz, root, rootsz);
    isroot[root] = true;
    int result = calc(root, 0, 0);
    for (int e = adj[root], v = gto[e]; ~e; v = gto[e = gnxt[e]])
        if (!isroot[v]) result -= calc(v, root, gw[e]), result += dfs(v);
    return result;
}

int gcd(int m, int n) {
    for (int r = m % n; r; m = n, n = r, r = m % n); return n;
}

int main() {
    memset(adj, 0xff, sizeof adj);
    scanf("%d", &n);
    for (int i = 1; i != n; ++i) {
        int x, y, w; scanf("%d%d%d", &x, &y, &w);
        add_edge(x, y, w % 3); add_edge(y, x, w % 3);
    }
    int pair = dfs(1), g = gcd(pair, n * n);
    printf("%d/%d\n", pair / g, n * n / g);
    return 0;
}
