#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, R, C;
char map[200][200];
int adj[22505], gto[45005], gnxt[45005], e;
int pre[22505], cap[22505], flw[22505];
int q[22505], h, t, dis[22505];

inline void reverse_bfs(int s) {
    memset(dis, 0, sizeof dis);
    for (dis[q[h = t = 0] = s] = 1; h <= t; ++h)
        for (int u = q[h], e = adj[u]; ~e; e = gnxt[e])
            if (!dis[gto[e]]) dis[gto[e]] = dis[u] + 1, q[++t] = gto[e];
}

inline int augment(int s, int t) {
    int aug = 1000;
    for (int u = t, e = pre[u]; u ^ s; e = pre[u])
        aug = min(aug, cap[e] - flw[e]), u = gto[e ^ 1];
    for (int u = t; u ^ s; u = gto[pre[u] ^ 1])
        flw[pre[u]] += aug, flw[pre[u] ^ 1] -= aug;
    return aug;
}

int num[22505], cur[22505];
inline int isap(int s, int t) {
    memset(pre, 0, sizeof pre);
    int flow = 0; memset(num, 0, sizeof num);
    reverse_bfs(t); for (int i = 0; i <= R * C + 1; ++num[dis[i++]]);
    memcpy(cur, adj, sizeof cur); int u = s;
    while (dis[s] <= R * C + 1) {
        if (u == t) flow += augment(s, t), u = s;
        bool adv = false;
        for (int e = cur[u]; ~e && !adv; e = gnxt[e])
            if (cap[e] > flw[e] && dis[gto[e]] + 1 == dis[u])
                adv = true, pre[gto[e]] = e, cur[u] = e, u = gto[e];
        if (!adv) {
            int m = R * C;
            for (int e = adj[u]; ~e; e = gnxt[e])
                if (cap[e] > flw[e] && dis[gto[e]])
                    m = min(m, dis[gto[e]]);
            if (--num[dis[u]] == 0) break;
            ++num[dis[u] = m + 1]; cur[u] = adj[u];
            if (u ^ s) u = gto[pre[u] ^ 1];
        }
    }
    return flow;
}

bool ismap(char c) {
    return c == 'X' || c == '.' || c == 'D';
}

void add_edge(int u, int v, int c) {
    gto[e] = v; cap[e] = c; gnxt[e] = adj[u]; adj[u] = e++;
}

void build() {
    memset(adj, -1, sizeof adj); e = 0;
    memset(flw, 0, sizeof flw);
    for (int r = 0; r != R; ++r)
        for (int c = 0; c != C; ++c)
            if (map[r][c] != 'X') {
                if (r != 0 && map[r - 1][c] != 'X') {
                    add_edge(r * C + c, (r - 1) * C + c, 1);
                    add_edge((r - 1) * C + c, r * C + c, 1);
                }
                if (c != 0 && map[r][c - 1] != 'X') {
                    add_edge(r * C + c, r * C + c - 1, 1);
                    add_edge(r * C + c - 1, r * C + c, 1);
                }
            }
    for (int r = 0; r != R; ++r)
        for (int c = 0; c != C; ++c)
            if (map[r][c] == 'D') {
                add_edge(R * C, r * C + c, 1000);
                add_edge(r * C + c, R * C, 1000);
            }
    for (int r = 0; r != R; ++r) {
        if (map[r][0] != 'X') {
            add_edge(R * C + 1, r * C, 1);
            add_edge(r * C, R * C + 1, 1);
        }
        if (map[r][C - 1] != 'X') {
            add_edge(R * C + 1, r * C + C - 1, 1);
            add_edge(r * C + C - 1, R * C + 1, 1);
        }
    }
    for (int c = 0; c != C; ++c) {
        if (map[0][c] != 'X') {
            add_edge(R * C + 1, c, 1);
            add_edge(c, R * C + 1, 1);
        }
        if (map[R - 1][c] != 'X') {
            add_edge(R * C + 1, R * C - C + c, 1);
            add_edge(R * C - C + c, R * C + 1, 1);
        }
    }
}

void print_graph() {
    printf("src:");
    for (int e = adj[R * C]; ~e; e = gnxt[e])
        printf(" (%d, %d)", gto[e] / C, gto[e] % C);
    putchar('\n');
    for (int i = 0; i != R * C; ++i) {
        if (map[i / C][i % C] == 'X') continue;
        printf("(%d, %d):", i / C, i % C);
        for (int e = adj[i]; ~e; e = gnxt[e]) {
            if (gto[e] < R * C) printf(" (%d, %d)", gto[e] / C, gto[e] % C);
            else if (gto[e] == R * C) printf(" src");
            else if (gto[e] == R * C + 1) printf(" dst");
        }
        putchar('\n');
    }
    printf("dst:");
    for (int e = adj[R * C + 1]; ~e; e = gnxt[e])
        printf(" (%d, %d)", gto[e] / C, gto[e] % C);
    putchar('\n');
}

int main() {
    for (scanf("%d", &N); N; --N) {
        scanf("%d%d", &R, &C);
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
                while (!ismap(map[r][c] = getchar()));
        if (R == 1 && C == 1) {
            puts("4");
            continue;
        }
        if (R == 1) {
            int flow = 4;
            for (int i = 0; map[0][i] != 'D'; ++i)
                if (map[0][i] == 'X') {
                    --flow; break;
                }
            for (int i = C - 1; map[0][i] != 'D'; --i)
                if (map[0][i] == 'X') {
                    --flow; break;
                }
            printf("%d\n", flow);
            continue;
        }
        if (C == 1) {
            int flow = 4;
            for (int i = 0; map[i][0] != 'D'; ++i)
                if (map[i][0] == 'X') {
                    --flow; break;
                }
            for (int i = R - 1; map[i][0] != 'D'; --i)
                if (map[i][0] == 'X') {
                    --flow; break;
                }
            printf("%d\n", flow);
            continue;
        }
        build();
        //print_graph();
        int mini = isap(R * C, R * C + 1);
        printf("%d\n", mini);
    }
}
