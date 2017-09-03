#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

template <typename T>
T get() {
    char c; while (!isdigit(c = getchar()) && c != '-');
    bool neg = c == '-'; T r = neg ? 0 : c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return neg ? -r : r;
}

template <typename T>
void putint(T x) {
    static char buf[sizeof(T) << 2];
    static int len = 0;
    if (x < 0) putchar('-'), x = -x;
    do buf[len++] = x % 10; while (x /= 10);
    while (--len) putchar(buf[len] + '0');
    putchar(*buf + '0');
}

using namespace std;

int n, k;
int adj[10005], gto[20005], glen[20005], gnxt[20005], e;
int size[10005];
bool vis[10005];

inline void add_edge(int u, int v, int w) {
    gto[e] = v; glen[e] = w; gnxt[e] = adj[u]; adj[u] = e++;
}

int getsize(int node, int pre) {
    size[node] = 1;
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (gto[e] != pre && !vis[gto[e]])
            size[node] += getsize(gto[e], node);
    return size[node];
}

void getroot(int node, int pre, int subsz, int &root, int &rootsz) {
    int maxsz = subsz - size[node];
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (gto[e] != pre && !vis[gto[e]]) {
            getroot(gto[e], node, subsz, root, rootsz);
            maxsz = max(maxsz, size[gto[e]]);
        }
    if (maxsz < rootsz) rootsz = maxsz, root = node;
}

int dis[10005], nodenum;
int getdis(int node, int pre, int d) {
    dis[nodenum++] = d;
    for (int e = adj[node]; ~e; e = gnxt[e])
        if (!vis[gto[e]] && gto[e] != pre)
            getdis(gto[e], node, d + glen[e]);
}

int count(int node, int d) {
    int result = 0;
    nodenum = 0;
    getdis(node, 0, d);
    sort(dis, dis + nodenum);
    for (int i = 0, j = nodenum - 1; i < j; ++i) {
        while (dis[i] + dis[j] > k && i < j) --j;
        result += j - i;
    }
    return result;
}

int dfs(int node) {
    int subsz = getsize(node, 0);
    int root, rootsz = ~0u >> 1;
    getroot(node, 0, subsz, root, rootsz);
    vis[root] = true;
    int result = count(root, 0);
    for (int e = adj[root], v = gto[e]; ~e; v = gto[e = gnxt[e]])
        if (!vis[v]) result -= count(v, glen[e]), result += dfs(v);
    return result;
}

void initialize() {
    memset(adj, 0xff, sizeof adj);
    memset(vis, false, sizeof vis);
    e = 0;
}

int main() {
    n = get<int>(), k = get<int>();
    while (n || k) {
        initialize();
        for (int i = 1; i != n; ++i) {
            int u = get<int>(), v = get<int>(), l = get<int>();
            add_edge(u, v, l); add_edge(v, u, l);
        }
        putint(dfs(1)); putchar('\n');
        n = get<int>(), k = get<int>();
    }
    return 0;
}
