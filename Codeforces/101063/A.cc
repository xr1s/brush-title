#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const long double pi = 4.l * atan(1.l);

int N, r[100005], Q;
int s[100005], t[100005];
pair<int, long double> open[100005];
int adj[100005], gto[500005], gnxt[500005], e;
long double gdis[500005], dis[100005];

long double radius_distance(long double l, long double r) {
    long double diff = l - r;
    if (diff < 0) diff += 2 * pi;
    if (diff > pi) diff = 2 * pi - diff;
    return diff;
}

void add_edge(int u, int v, long double dis) {
    gto[e] = v; gdis[e] = dis; gnxt[e] = adj[u]; adj[u] = e++;
}

void add_neighbour(int id) {
    const pair<int, long double> &door = open[id];
    int n = door.first; long double radius = door.second;
    pair<int, long double> inner = make_pair(n - 1, radius);
    int succ = lower_bound(open + s[n - 1], open + t[n - 1], inner) - open;
    if (succ == t[n - 1]) succ = s[n - 1];
    long double succ_dist = radius_distance(door.second, open[succ].second);
    add_edge(succ, id, succ_dist * (r[door.first] + r[open[succ].first]) / 2.l);
    int prev = upper_bound(open + s[n - 1], open + t[n - 1], inner) - open - 1;
    if (prev == s[n - 1] - 1) prev = t[n - 1] - 1;
    long double prev_dist = radius_distance(door.second, open[prev].second);
    add_edge(prev, id, prev_dist * (r[door.first] + r[open[prev].first]) / 2.l);
}

int vis[100005], qu[100005], qh, qt;
long double bellman_ford(int s, int t, int n) {
    fill(dis, dis + n, 1e18); dis[s] = 0;
    for (vis[qu[qh = qt = 0] = s] = 1; qh <= qt; vis[qh++ % n] = 0)
        for (int e = adj[qu[qh % n]], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (dis[v] > dis[qu[qh % n]] + gdis[e]) {
                dis[v] = dis[qu[qh % n]] + gdis[e];
                if (!vis[v]) qu[++qt % n] = v;
            }
    return dis[t];
}

void print_neighbour(int u) {
    for (int e = adj[u]; ~e; e = gnxt[e])
        printf("%d %Lf\n", gto[e], gdis[e]);
    putchar('\n');
}

int main() {
    memset(adj, -1, sizeof adj);
    scanf("%d", &N);
    for (int i = 0; i != N; ++i) scanf("%d", &r[i]);
    sort(r, r + N);
    scanf("%d", &Q);
    for (int i = 0; i != Q; ++i) {
        int ri; long double d; scanf("%d%Lf", &ri, &d);
        int n = lower_bound(r, r + N, ri) - r;
        open[i] = make_pair(n, d);
    }
    sort(open, open + Q);
    s[0] = 0; t[N - 1] = Q;
    for (int i = 1; i != Q; ++i) {
        if (open[i].first != open[i - 1].first) {
            t[open[i - 1].first] = i;
            s[open[i].first] = i;
        }
    }
    for (int i = s[0]; i != t[0]; ++i) add_edge(Q, i, 0);
    for (int i = s[N - 1]; i != t[N - 1]; ++i) add_edge(i, Q + 1, 0);
    for (int i = s[1]; i != t[N - 1]; ++i) add_neighbour(i);
    long double ans = bellman_ford(Q, Q + 1, Q + 2);
    printf("%.5Lf\n", ans + r[N - 1]);
    return 0;
}
