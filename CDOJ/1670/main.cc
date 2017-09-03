#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long T, N, a[100005];
long long trie[3200005][2], node;

void insert(long long x) {
    long long rt = 0;
    for (long long i = 30; ~i; --i) {
        bool dir = x & 1ll << i;
        if (!trie[rt][dir])
            trie[rt][dir] = ++node;
        rt = trie[rt][dir];
    }
}

long long maximum(long long x) {
    long long rt = 0, val = 0;
    for (long long i = 30; ~i; --i) {
        bool dir = ~x & 1ll << i;
        if (!trie[rt][dir]) dir ^= 1;
        rt = trie[rt][dir];
        val |= (long long)(dir) << i;
    }
    return val;
}

int main() {
    for (scanf("%lld", &T); T; --T) {
        long long maxi = 0;
        memset(trie, 0, sizeof trie); node = 0;
        scanf("%lld", &N);
        for (long long i = 1; i <= N; ++i) scanf("%lld", &a[i]);
        insert(a[0]);
        for (long long i = 1; i <= N; ++i) {
            insert(a[i] ^= a[i - 1]);
            maxi = max(maxi, maximum(a[i]) ^ a[i]);
        }
        printf("%lld\n", maxi);
    }
    return 0;
}
