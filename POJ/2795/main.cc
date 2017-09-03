#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int h, w, n;
int tree[800000], node;

void build(int n) {
    memset(tree, 0x00, sizeof tree);
    for (node = 1; node < n; node <<= 1);
    for (int i = 0; i != n; ++i) tree[node + i] = w;
    for (int i = node - 1; i; --i)
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

int query(int w) {
    if (tree[1] < w) return -2;
    int root = 1;
    while ((root <<= 1) < node << 1)
        if (tree[root] < w) root |= 1;
    return (root >> 1) - node;
}

void subtract(int p, int v) {
    tree[p += node] -= v;
    while (p >>= 1)
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

int main() {
    while (~scanf("%d%d%d", &h, &w, &n)) {
        build(min(n, h));
        while (n--) {
            int wi; scanf("%d", &wi);
            int i = query(wi) + 1;
            printf("%d\n", i);
            if (~i) subtract(i - 1, wi);
        }
    }
    return 0;
}
