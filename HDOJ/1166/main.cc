#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

long long N, T;
long long tree[131072];
long long node;

void build(long long n) {
    for (node = 1; node < n + 2; node <<= 1);
    for (long long i = 1; i <= n; ++i)
        scanf("%lld", &tree[node + i]);
    for (long long i = node - 1; ~i; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void update(long long p, long long v) {
    tree[p += node] += v;
    while (p >>= 1) tree[p] += v;
}

long long query(long long l, long long r) {
    long long sum = 0;
    for (--l += node, ++r += node; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1) sum += tree[l ^ 1];
        if (r & 1)  sum += tree[r ^ 1];
    }
    return sum;
}

int main() {
    scanf("%lld", &T);
    for (long long kase = 1; kase <= T; ++kase) {
        memset(tree, 0, node * sizeof *tree);
        scanf("%lld", &N);
        build(N);
        printf("Case %lld:\n", kase);
        int cmd, i, j;
        while (!isalpha(cmd = getchar()));
        scanf("%*s");
        while (cmd != 'E') {
            scanf("%d%d", &i, &j);
            switch (cmd) {
                case 'A': update(i, j); break;
                case 'S': update(i, -j); break;
                case 'Q': printf("%lld\n", query(i, j)); break;
            }
            while (!isalpha(cmd = getchar()));
            scanf("%*s");
        }
    }
    return 0;
}
