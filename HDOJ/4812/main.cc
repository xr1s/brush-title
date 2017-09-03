// HDU increase system stack
#pragma comment(linker,"/STACK:102400000,102400000")

#include <cstdio>
#include <cctype>
#include <cstring>
#include <utility>

template <typename T>
T get() {
    char c; while (!isdigit(c = getchar()) && c != '-');
    bool neg = c == '-'; T r = neg ? 0 : c - '0';
    while (isdigit(c = getchar())) (r *= 10) += c - '0';
    return neg ? -r : r;
}

template <>
char get<char>() {
    char c; while (!isgraph(c = getchar())); return c;
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

template <typename T>
std::pair<T, std::pair<T, T> > exgcd(T m, T n) {
    T x = 0, y = 1, xp = 1, yp = 0, xt, yt;
    for (T r = m % n, q = m / n; r; ) {
        xt = xp - q * x, xp = x, x = xt;
        yt = yp - q * y, yp = y, y = yt;
        m = n, n = r, r = m % n, q = m / n;
    }
    return std::make_pair(n, std::make_pair(x, y));
}

template <typename T>
T modinv(T m, T n) {
    std::pair<T, std::pair<T, T> > result = exgcd(m, n);
    T gcd = result.first, inv = result.second.first;
    T self = n / gcd;
    return (inv % self + self) % self;
}

#include <set>
#include <vector>
using namespace std;

const long long mod = 1000003LL;

int N, K;
long long v[100005];
int adj[100005], gto[200005], gnxt[200005], e;
bool isrt[100005];
int size[100005];
long long inv[mod];
int mini[mod];
//pair<int, int> path[100005];
int ed[100005];
long long kval[100005];
int pnum;
pair<int, int> answer;

void add_edge(int u, int v) {
    gto[e] = v; gnxt[e] = adj[u]; adj[u] = e++;
}

int getsize(int s, int p) {
    size[s] = 1;
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]])
            size[s] += getsize(gto[e], s);
    return size[s];
}

void getroot(int s, int p, int sz, int &rt, int &rtsz) {
    int maxsz = sz - size[s];
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]]) {
            getroot(gto[e], s, sz, rt, rtsz);
            maxsz = max(maxsz, size[gto[e]]);
        }
    if (maxsz < rtsz) rt = s, rtsz = maxsz;
}

void getanswer(int s, int p, long long k) {
    ed[pnum] = s; kval[pnum++] = k;
    for (int e = adj[s]; ~e; e = gnxt[e])
        if (gto[e] != p && !isrt[gto[e]])
            getanswer(gto[e], s, k * v[gto[e]] % mod);
}

int dfs(int s) {
    int subsz = getsize(s, 0);
    int root, rootsz = ~0u >> 1;
    getroot(s, 0, subsz, root, rootsz);
    isrt[root] = true;
    set<int> calc;
    for (int e = adj[root]; ~e; e = gnxt[e])
        if (!isrt[gto[e]]) {
            pnum = 0;
            getanswer(gto[e], root, v[gto[e]]);
            //vector<pair<int, int> >::iterator i;
            for (int i = 0; i != pnum; ++i) {
                long long other = inv[kval[i] * v[root] % mod] * K % mod;
                if (mini[other] != 0x7f7f7f7f) {
                    int l = min(mini[other], ed[i]);
                    int r = max(mini[other], ed[i]);
                    answer = min(answer, make_pair(l, r));
                }
            }
            for (int i = 0; i != pnum; ++i) {
                mini[kval[i]] = min(mini[kval[i]], ed[i]);
                calc.insert((int)kval[i]);
            }
        }
    if (mini[inv[v[root]] * K % mod] != 0x7f7f7f7f) {
        int other = mini[inv[v[root]] * K % mod];
        answer = min(answer, make_pair(min(root, other), max(root, other)));
    }
    set<int>::iterator it = calc.begin();
    while (it != calc.end()) mini[*it++] = 0x7f7f7f7f;
    calc.clear();
    for (int e = adj[root]; ~e; e = gnxt[e])
        if (!isrt[gto[e]]) dfs(gto[e]);
}

void initialize(int N) {
    memset(adj + 1, 0xff, N * sizeof *adj);
    memset(isrt, 0x00, sizeof isrt);
    answer.first = answer.second = 0x7fffffff;
    e = 0;
}

int main() {
    memset(mini, 0x7f, sizeof mini);
    for (long long i = 1; i != mod; ++i)
        if (!inv[i]) {
            long long v = modinv(i, mod);
            inv[i] = v; inv[v] = i;
        }
    while (scanf("%d%d", &N, &K) != EOF) {
        initialize(N);
        for (int i = 1; i <= N; ++i) v[i] = get<long long>();
        for (int i = 1; i != N; ++i) {
            int x = get<int>(), y = get<int>();
            add_edge(x, y); add_edge(y, x);
        }
        dfs(1);
        if (answer != make_pair(0x7fffffff, 0x7fffffff)) {
            putint(answer.first);
            putchar(' ');
            putint(answer.second);
            putchar('\n');
        } else puts("No solution");
    }
    return 0;
}
