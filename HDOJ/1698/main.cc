#include <cstdio>
#include <cstring>

using namespace std;

int T, N, Q, X, Y, Z;
int tree[400000], lazy[400000];

void push_up(int RT) {
    tree[RT] = tree[RT << 1] + tree[RT << 1 | 1];
}

void push_down(const int RT, const int L, const int R) {
    if (!~lazy[RT]) return;
    int M = L + R >> 1;
    tree[RT << 1 | 0] = lazy[RT] * (M - L);
    tree[RT << 1 | 1] = lazy[RT] * (R - M);
    lazy[RT << 1] = lazy[RT << 1 | 1] = lazy[RT];
    lazy[RT] = -1;
}

void build(const int RT, const int L, const int R) {
    if (L + 1 == R) {
        tree[RT] = 1;
        return;
    }
    int M = L + R >> 1;
    build(RT << 1 | 0, L, M);
    build(RT << 1 | 1, M, R);
    push_up(RT);
}

void update(int l, int r, int v, const int RT, const int L, const int R) {
    if (l <= L && R <= r) {
        tree[RT] = v * (R - L);
        lazy[RT] = v;
        return;
    }
    push_down(RT, L, R);
    int M = L + R >> 1;
    if (l < M) update(l, r, v, RT << 1 | 0, L, M);
    if (r > M) update(l, r, v, RT << 1 | 1, M, R);
    push_up(RT);
}

int main() {
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d%d", &N, &Q);
        memset(lazy, 0xff, sizeof lazy);
        memset(tree, 0x00, sizeof tree);
        build(1, 0, N);
        while (Q--) {
            scanf("%d%d%d", &X, &Y, &Z);
            update(X - 1, Y, Z, 1, 0, N);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase, tree[1]);
    }
    return 0;
}
