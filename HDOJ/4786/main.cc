#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 100005;
const int maxM = 100005;

int T, N, M, u, v, c;
struct edge {
    int u, v, c;
} e[maxM];
int f[maxN];
int fib[32] = { 1, 2 };

int find(int x) {
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}

void unite(int u, int v) {
    f[find(v)] = find(u);
}

bool white(const edge &lhs, const edge &rhs) {
    return lhs.c > rhs.c;
}

bool black(const edge &lhs, const edge &rhs) {
    return lhs.c < rhs.c;
}

template <typename func>
int kruskal(edge e[], const func &cmp) {
    int ecnt = 0;
    for (int i = 1; i <= N; ++i) f[i] = i;
    sort(e, e + M, cmp);
    int weight = 0;
    for (int i = 0; i != M; ++i) {
        if (find(e[i].u) == find(e[i].v)) continue;
        weight += e[i].c; unite(e[i].u, e[i].v);
        ++ecnt;
    }
    if (ecnt != N - 1) return -1;
    return weight;
}

int main() {
    for (int i = 2; i != sizeof fib / sizeof *fib; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i != M; ++i)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
        int maxi = kruskal(e, white), mini = kruskal(e, black);
        if (maxi == -1 || mini == -1) {
            printf("Case #%d: No\n", cs); continue;
        }
        int *minp = lower_bound(fib, fib + sizeof fib / sizeof *fib, mini);
        int *maxp = upper_bound(fib, fib + sizeof fib / sizeof *fib, maxi);
        printf("Case #%d: %s\n", cs, minp == maxp ? "No" : "Yes");
    }
    return 0;
}
