#include <cctype>
#include <cstdio>
#include <type_traits>

template <typename T>
constexpr bool is_integral_v = std::is_integral<T>::value;

template <typename T, typename = std::enable_if_t<is_integral_v<T>>>
T get() {
    char c; while (!isdigit(c = getchar()) && c != '-');
    bool neg = c == '-'; T r = neg ? 0 : c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return neg ? -r : r;
}

template <>
char get() {
    char c; while (!isgraph(c = getchar())); return c;
}

template <typename T, typename = std::enable_if_t<is_integral_v<T>>>
void putint(T x) {
    static char buf[sizeof(T) << 2];
    static std::size_t len = 0;
    if (x < 0) putchar('-'), x = -x;
    do buf[len++] = x % 10; while (x /= 10);
    while (--len) putchar(buf[len] + '0');
    putchar(*buf + '0');
}

#include <cstring>
using namespace std;

constexpr int maxN = 100005;
constexpr int maxM = 200005;
constexpr int maxW = 1000000000;
int T, N, M, K;
int adj[maxN], gto[maxM], gnxt[maxM], e;
long long gw[maxM], gc[maxM];
int qu[maxN], qh, qt, inq[maxN];
long long dis[maxN];

void add_edge(int u, int v, long long c, long long w) {
    gto[e] = v; gw[e] = w; gc[e] = c; gnxt[e] = adj[u]; adj[u] = e++;
}

bool bellman_ford(int s, int t, int W) {
    memset(dis + 1, 0x7f, N * sizeof *dis); dis[s] = 0;
    for (inq[qu[qh = qt = 0] = s] = 1; qh <= qt; inq[qu[qh++ % N]] = 0)
        for (int e = adj[qu[qh % N]], v = gto[e]; ~e; v = gto[e = gnxt[e]])
            if (dis[v] > dis[qu[qh % N]] + gc[e] && gw[e] <= W) {
                dis[v] = dis[qu[qh % N]] + gc[e];
                if (!inq[v]) inq[qu[++qt % N] = v] = 1;
            }
    return dis[t] < K;
}

int main() {
    for (T = get<int>(); T; --T) {
        N = get<int>(); M = get<int>(); K = get<int>();
        memset(adj + 1, 0xff, N * sizeof *adj); e = 0;
        for (int i = 0; i != M; ++i) {
            auto s1 = get<int>(), s2 = get<int>();
            auto c = get<long long>(), W = get<long long>();
            add_edge(s1, s2, c, W); add_edge(s2, s1, c, W);
        }
        int bnd[2] = { 0, maxW + 1 };
        while (bnd[0] + 1 != bnd[1]) {
            int m = bnd[0] + bnd[1] >> 1;
            bnd[bellman_ford(1, N, m)] = m;
        }
        if (bnd[1] == maxW + 1) puts("-1");
        else  printf("%d\n", bnd[1]);
    }
    return 0;
}
