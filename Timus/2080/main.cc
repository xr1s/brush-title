#include <cstdio>
#include <queue>
#include <set>
#include <list>
#include <utility>
using namespace std;

int n, k;
int a[100005];
list<int> nxt[100005];
int stk[100005], stktop;
int bit[400005];

int lowbit(int x) {
    return x & -x;
}

void inc(int p) {
    for (int i = p; i <= k; i += lowbit(i)) ++bit[i];
}

void dec(int p) {
    for (int i = p; i <= k; i += lowbit(i)) --bit[i];
}

int query(int p) {
    int r = 0;
    for (int i = p; i; i -= lowbit(i)) r += bit[i];
    return r;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &a[i]);
        if (nxt[a[i]].empty())
            stk[stktop++] = a[i], inc(i);
        nxt[a[i]].push_back(i);
    }
    printf("%d", stk[0]);
    for (int i = 1; i != stktop; ++i) printf(" %d", stk[i]);
    for (int i = 1; i <= n; ++i) if (nxt[i].empty()) printf(" %d", i);
    putchar('\n');
    for (int i = 1; i <= k; ++i) {
        dec(i);
        nxt[a[i]].pop_front();
        if (!nxt[a[i]].empty()) {
            int p = nxt[a[i]].front();
            printf("%d\n", query(p - 1));
            inc(p);
        } else printf("%d\n", n - 1);
    }
    return 0;
}
