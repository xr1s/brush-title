#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[5005];
int bit[5005];

inline int lowbit(int x) {
    return x & -x;
}

void insert(int x) {
    for (; x <= n; x += lowbit(x)) ++bit[x];
}

int query(int x) {
    int sum = 0;
    do sum += bit[x];
    while (x -= lowbit(x));
    return sum;
}

int main() {
    while (~scanf("%d", &n)) {
        memset(bit, 0x00, sizeof bit);
        int rev = 0, ans = ~0u >> 1;
        for (int i = 0; i != n; ++i) {
            scanf("%d", &a[i]), ++a[i];
            rev += i - query(a[i]);
            insert(a[i]);
        }
        for (int i = 0; i != n; ++i)
            ans = min(ans, rev += n + 1 - a[i] * 2);
        printf("%d\n", ans);
    }
    return 0;
}
