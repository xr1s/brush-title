#include <cstdio>
#include <cstdlib>
using namespace std;

long long n, a[55];
long long can[70];

void dfs(long long bit, long long l, long long r) {
    if (bit == -1) return;
    long long change = 0, split = 0;
    for (long long i = l + 1; i != r; ++i)
        if ((a[i] & (1ll << bit)) ^ (a[i - 1] & (1ll << bit))) {
            ++change; split = i;
        }
    if (!change) {
        dfs(bit - 1, l, r);
        return;
    } else if (change == 1) {
        dfs(bit - 1, l, split);
        dfs(bit - 1, split, r);
        if ((a[l] & 1ll << bit) < (a[split] & 1ll << bit))
            can[bit] &= 1ll;
        else can[bit] &= 2ll;
        return;
    } else if (change > 1) {
        puts("0");
        exit(0);
    }
}

constexpr long long start = 60;

int main() {
    scanf("%lld", &n);
    for (long long i = 0; i != 64; ++i) can[i] = 3;
    for (long long i = 0; i != n; ++i) scanf("%lld", &a[i]);
    dfs(59, 0, n);
    long long ans = 1;
    for (long long i = 0; i != start; ++i) {
        long long count = 0;
        if (can[i] & 1ll) ++count;
        if (can[i] & 2ll) ++count;
        ans *= count;
    }
    printf("%lld\n", ans);
    return 0;
}
