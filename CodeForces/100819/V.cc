#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

int n;
int x[1005], y[1005], r[1005];
bitset<1005> adj[1005];
int qu[1005], qh, qt;
int pre[1005], dis[1005];

int sqr(int x) {
    return x * x;
}

int gcd(int m, int n) {
    int r;
    while ((r = m % n)) m = n, n = r;
    return n;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
        for (int j = 0; j != i; ++j)
            if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) == sqr(r[i] + r[j]))
                adj[i].set(j), adj[j].set(i);
    }
    memset(pre, -1, sizeof pre);
    for (qu[qh = qt = 0] = 0; qh <= qt; ++qh)
        for (int u = qu[qh], v = 0; v != n; ++v)
            if (adj[u][v] && v != pre[u]) {
                if (!~pre[v]) dis[v] = dis[pre[qu[++qt] = v] = u] + 1;
                else if (r[pre[v]] != r[u] || ((dis[pre[v]] & 1) != (dis[u] & 1))) {
                    puts("The input gear cannot move.");
                    return 0;
                }
            }
    if (~pre[n - 1]) {
        if (dis[n - 1] & 1) putchar('-');
        int g = gcd(r[0], r[n - 1]);
        printf("%d:%d\n", r[0] / g, r[n - 1] / g);
    } else puts("The input gear is not connected to the output gear.");
    return 0;
}
