#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int tree[524288];
int node;

void build(int n) {
    for (node = 1; node < n + 2; node <<= 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &tree[node + i]);
    for (int i = node - 1; i; --i)
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

void update(int p, int v) {
    tree[p += node] = v;
    while (p >>= 1)
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

int query(int l, int r) {
    int maximum = 1 << 31;
    for (--l += node, ++r += node; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1) maximum = max(maximum, tree[l ^ 1]);
        if (r & 1)  maximum = max(maximum, tree[r ^ 1]);
    }
    return maximum;
}

int main() {
    while (~scanf("%d%d", &N, &M)) {
        memset(tree, 0x80, sizeof tree);
        build(N);
        while (M--) {
            int cmd, A, B;
            while (!isalpha(cmd = getchar()));
            scanf("%d%d", &A, &B);
            switch (cmd) {
                case 'U': update(A, B); break;
                case 'Q': printf("%d\n", query(A, B)); break;
            }
        }
    }
    return 0;
}
