#include <cstdio>
#include <cstring>

using namespace std;

int N;
int adj[5005], gto[10005], gnxt[10005], gprv[10005], e;
int stk[10005], stktop;
int travesal[10005], trvtop;
int dis[10005];
int to[4005];

void add_edge(int u, int v) {
    gto[e] = v; gnxt[e] = adj[u];
    if (~adj[u]) gprv[adj[u]] = e;
    adj[u] = e++;
}

void del_edge(int s, int e) {
    int prev = gprv[e], succ = gnxt[e];
    if (prev == -1) adj[s] = succ;
    else gnxt[prev] = succ;
    if (succ != -1) gprv[succ] = prev;
}

void print_edge(int s) {
    printf("%d:", s);
    for (int e = adj[s]; ~e; e = gnxt[e])
        printf(" %d", gto[e]);
    putchar('\n');
}

void travel(int s) {
    bool find;
    do {
        stk[stktop++] = s;
        find = false;
        for (int e = adj[s]; ~e; e = gnxt[e]) {
            find = true;
            int t = gto[e];
            del_edge(t, e ^ 1);
            del_edge(s, e);
            s = t;
            break;
        }
    } while (find);
}

void fluery(int s) {
    stk[stktop++] = s;
    while (stktop)
        if (~adj[stk[--stktop]]) travel(stk[stktop]);
        else travesal[trvtop++] = stk[stktop];
}

int qu[10005], qh, qt;
void bfs(int s) {
    for (dis[qu[qh = qt = 0] = s] = 1; qh <= qt; ++qh)
        for (int e = adj[qu[qh]]; ~e; e = gnxt[e])
            if (!dis[gto[e]]) dis[qu[++qt] = gto[e]] = dis[qu[qh]] + 1;
}

int main() {
    freopen("courier.in", "r", stdin);
    freopen("courier.out", "w", stdout);
    memset(adj, -1, sizeof adj);
    memset(gnxt, -1, sizeof gnxt);
    memset(gprv, -1, sizeof gprv);
    scanf("%d", &N);
    for (int i = 0; i != N << 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        int uc = u + 3 >> 2, vc = v + 3 >> 2;
        add_edge(uc, vc); add_edge(vc, uc);
        to[u] = v; to[v] = u;
    }
    bfs(1);
    for (int i = 1; i <= N; ++i)
        if (!dis[i]) {
            puts("No");
            return 0;
        }
    fluery(1);
    puts("Yes");
    int cur = 0;
    while (travesal[cur] != 1) ++cur;
    for (int i = 0; i != trvtop; ++i) {
        bool find = false;
        int nxt = (cur + 1) % trvtop;
        for (int j = -3; j != 1; ++j) {
            for (int k = -3; k != 1; ++k)
                if (to[travesal[cur] * 4 + j] == travesal[nxt] * 4 + k) {
                    if (i) putchar(' ');
                    printf("%d", travesal[cur] * 4 + j);
                    printf(" %d", travesal[nxt] * 4 + k);
                    to[travesal[cur] * 4 + j] = 0;
                    to[travesal[nxt] * 4 + k] = 0;
                    ++cur %= trvtop; ++nxt %= trvtop;
                    find = true;
                    break;
                }
            if (find) break;
        }
    }
    putchar('\n');
    return 0;
}
