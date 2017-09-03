#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int c, n;
int tree[160005];
int disc[100005], cnt;
int q[10005][2];
set<int> color;

void push_down(int RT) {
    if (!tree[RT]) return;
    tree[RT << 1] = tree[RT << 1 | 1] = tree[RT];
    tree[RT] = 0;
}

void update(int l, int r, int c, int RT, int L, int R) {
    if (l <= L && R <= r) {
        tree[RT] = c;
        return;
    }
    push_down(RT);
    int M = L + R >> 1;
    if (l < M) update(l, r, c, RT << 1 | 0, L, M);
    if (M < r) update(l, r, c, RT << 1 | 1, M, R);
}

void query(int RT, int L, int R) {
    if (L + 1 == R) {
        if (tree[RT])
            color.insert(tree[RT]);
        return;
    }
    push_down(RT);
    int M = L + R >> 1;
    query(RT << 1 | 0, L, M);
    query(RT << 1 | 1, M, R);
}

int main() {
    ios::sync_with_stdio(false);
    for (cin >> c; c; --c) {
        memset(tree, 0x00, sizeof tree);
        memset(disc, 0x00, sizeof disc);
        cnt = 0;
        cin >> n;
        for (int i = 0; i != n; ++i) {
            cin >> q[i][0] >> q[i][1];
            disc[cnt++] = --q[i][0];
            disc[cnt++] = q[i][1];
        }
        sort(disc, disc + cnt);
        cnt = unique(disc, disc + cnt) - disc;
        for (int i = cnt - 1; i; --i)
            if (disc[i] - disc[i - 1] > 1)
                disc[cnt++] = disc[i] + disc[i - 1] >> 1;
        sort(disc, disc + cnt);
        cnt = unique(disc, disc + cnt) - disc;
        for (int i = 0; i != n; ++i) {
            int l = lower_bound(disc, disc + cnt, q[i][0]) - disc;
            int r = lower_bound(disc, disc + cnt, q[i][1]) - disc;
            update(l, r, i + 1, 1, 0, cnt);
        }
        query(1, 0, cnt);
        cout << color.size() << '\n';
        color.clear();
    }
    return 0;
}
