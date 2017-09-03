#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int N, Q, a, b, c;
long long tree[400005], lazy[400005];

void push_down(int RT, int L, int R) {
    int M = L + R >> 1;
    tree[RT << 1 | 0] += lazy[RT] * (M - L);
    tree[RT << 1 | 1] += lazy[RT] * (R - M);
    lazy[RT << 1 | 0] += lazy[RT];
    lazy[RT << 1 | 1] += lazy[RT];
    lazy[RT] = 0;
}

void push_up(int RT) {
    tree[RT] = tree[RT << 1] + tree[RT << 1 | 1];
}

void build(int RT, int L, int R) {
    if (L + 1 != R) {
        int M = L + R >> 1;
        build(RT << 1 | 0, L, M);
        build(RT << 1 | 1, M, R);
        push_up(RT);
    } else scanf("%I64d", &tree[RT]);
}

void update(int l, int r, int v, int RT, int L, int R) {
    if (l <= L && R <= r) {
        tree[RT] += v * (R - L);
        lazy[RT] += v;
        return;
    }
    push_down(RT, L, R);
    int M = L + R >> 1;
    if (l < M) update(l, r, v, RT << 1 | 0, L, M);
    if (M < r) update(l, r, v, RT << 1 | 1, M, R);
    push_up(RT);
}

long long query(int l, int r, int RT, int L, int R) {
    if (l <= L && R <= r) return tree[RT];
    push_down(RT, L, R);
    int M = L + R >> 1;
    long long ret = 0;
    if (l < M) ret += query(l, r, RT << 1 | 0, L, M);
    if (r > M) ret += query(l, r, RT << 1 | 1, M, R);
    return ret;
}

int main() {
    scanf("%d%d", &N, &Q);
    build(1, 0, N);
    while (Q--) {
        int cmd; while (!isupper(cmd = getchar()));
        scanf("%d%d", &a, &b); if (a > b) swap(a, b);
        switch (cmd) {
            case 'C':
                scanf("%d", &c);
                update(a - 1, b, c, 1, 0, N);
                break;
            case 'Q':
                printf("%I64d\n", query(a - 1, b, 1, 0, N));
                break;
        }
    }
    return 0;
}
