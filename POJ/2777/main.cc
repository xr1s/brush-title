#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int L, T, O, A, B, C;
int tree[400005], lazy[400005];

void push_down(int RT) {
    if (!lazy[RT]) return;
    tree[RT << 1] = tree[RT << 1 | 1] = lazy[RT];
    lazy[RT << 1] = lazy[RT << 1 | 1] = lazy[RT];
    lazy[RT] = 0;
}

void push_up(int RT) {
    tree[RT] = tree[RT << 1] | tree[RT << 1 | 1];
}

void update(int l, int r, int c, int RT, int L, int R) {
    if (l <= L && R <= r) {
        tree[RT] = 1 << c;
        lazy[RT] = 1 << c;
        return;
    }
    push_down(RT);
    int M = L + R >> 1;
    if (l < M) update(l, r, c, RT << 1 | 0, L, M);
    if (M < r) update(l, r, c, RT << 1 | 1, M, R);
    push_up(RT);
}

int query(int l, int r, int RT, int L, int R) {
    if (l <= L && R <= r) return tree[RT];
    push_down(RT);
    int M = L + R >> 1, ret = 0;
    if (l < M) ret |= query(l, r, RT << 1 | 0, L, M);
    if (r > M) ret |= query(l, r, RT << 1 | 1, M, R);
    return ret;
}

int main() {
    lazy[1] = 1;
    for (scanf("%d%d%d", &L, &T, &O); O; --O) {
        int cmd; while (!isupper(cmd = getchar()));
        scanf("%d%d", &A, &B); if (A > B) swap(A, B);
        switch (cmd) {
            case 'C':
                scanf("%d", &C);
                update(A - 1, B, C - 1, 1, 0, L);
                break;
            case 'P':
                int num = query(A - 1, B, 1, 0, L), count = 0;
                for (int i = 0; i != 30; ++i) count += (num >> i) & 1;
                printf("%d\n", count);
                break;
        }
    }
    return 0;
}
