#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <bitset>
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


template <std::size_t n>
constexpr std::set<std::size_t> euler_sieve() {
    std::set<std::size_t> prime;
    std::bitset<n> is_prime; is_prime.set();
    for (std::size_t p = 2; p != n; ++p) {
        if (is_prime[p]) prime.insert(p);
        for (auto q: prime) {
            if (p * q > n) break;
            is_prime[p * q] = false;
            if (p % q == 0) break;
        }
    }
    return prime;
}

using namespace std;

constexpr int maxv = 50005;
constexpr int maxe = 100005;
auto prime = euler_sieve<50001>();
int adj[maxv], gto[maxe], gnxt[maxe], e;
int sz[maxv];
bool isrt[maxv];

void add_edge(int st, int ed) {
    gto[e] = ed; gnxt[e] = adj[st]; adj[st] = e++;
}

int getsize(int s, int p) {
    sz[s] = 1;
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]])
            sz[s] += getsize(gto[e], s);
    return sz[s];
}

void getroot(int s, int p, int sbsz, int &rt, int &rtsz) {
    int maxsz = sbsz - sz[s];
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]]) {
            getroot(gto[e], s, sbsz, rt, rtsz);
            maxsz = max(maxsz, sz[gto[e]]);
        }
    if (maxsz < rtsz) rtsz = maxsz, rt = s;
}

long long dist[maxv];
int dfsanswer(int s, int p, int now) {
    ++dist[now];
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]])
            dfsanswer(gto[e], s, now + 1);
}

long long getanswer(int s, int p, int init) {
    memset(dist, 0x00, sizeof dist);
    long long result = 0;
    dfsanswer(s, p, init);
    for (int i = init; i != maxv; ++i) {
        if (!dist[i]) break;
        auto it = prime.lower_bound(i + init);
        for (; it != prime.end(); ++it) {
            if (!dist[*it - i]) break;
            result += dist[*it - i] * dist[i];
        }
    }
    return result;
}

long long dfs(int s) {
    int sbsz = getsize(s, 0);
    int root, rootsz = ~0u >> 1;
    getroot(s, 0, sbsz, root, rootsz);
    isrt[root] = true;
    long long result = getanswer(root, 0, 0);
    for (int e = adj[root]; ~e; e = gnxt[e])
        if (!isrt[gto[e]]) {
            result -= getanswer(gto[e], root, 1);
            result += dfs(gto[e]);
        }
    return result;
}

int main() {
    memset(adj, 0xff, sizeof adj);
    long long N = get<long long>();
    for (int i = 1; i != N; ++i) {
        int a = get<int>(), b = get<int>();
        add_edge(a, b); add_edge(b, a);
    }
    printf("%.7lf\n", dfs(1) / (N * (N - 1.)));
    return 0;
}
