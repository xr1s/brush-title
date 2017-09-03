#include <cctype>
#include <cstdio>
using namespace std;

int n, m;
int destroy[50005], top;
bool tree[200000];
int node;
int p, s;

void build(int n) {
    for (node = 1; node < n + 2; node <<= 1);
    for (int i = 1; i <= n; ++i) tree[node + i] = 1;
    for (int i = n + 1; i != node; ++i) tree[node + i] = 0;
    for (int i = node - 1; i; --i)
        tree[i] = tree[i << 1] & tree[i << 1 | 1];
}

void update(int v, bool s) {
    tree[v += node] = s;
    for (v >>= 1; v; v >>= 1)
        tree[v] = tree[v << 1] & tree[v << 1 | 1];
}

int prev(int v) {
    if (!tree[v + node]) return v;
    for (v += node; v; v >>= 1)
        if (v & 1 && !tree[v ^ 1]) break;
    if ((v ^= 1) > node) return v - node;
    while ((v <<= 1) < node << 1) v |= !tree[v | 1];
    return (v >> 1) - node;
}

int succ(int v) {
    if (!tree[v + node]) return v;
    for (v += node; v; v >>= 1)
        if (~v & 1 && !tree[v ^ 1]) break;
    if ((v ^= 1) > node) return v - node;
    while ((v <<= 1) < node << 1) v |= tree[v | 0];
    return (v >> 1) - node;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        build(n);
        while (m--) {
            char cmd; int village;
            while (isspace(cmd = getchar()));
            switch (cmd) {
              case 'D':
                scanf("%d", &village);
                destroy[top++] = village;
                update(village, false);
                break;
              case 'Q':
                scanf("%d", &village);
                s = succ(village);
                p = prev(village);
                if (s == p) puts("0");
                else printf("%d\n", s - p - 1);
                break;
              case 'R':
                update(destroy[--top], true);
                break;
            }
        }
    }
    return 0;
}
