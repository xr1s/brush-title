#include <cstdio>
#include <cstring>

using namespace std;

long long N;
long long cnt[700000];

int main() {
    for (scanf("%lld", &N); N; --N) {
        memset(cnt, 0, sizeof cnt);
        long long tot = 0;
        long long a; scanf("%lld", &a);
        do ++cnt[a], ++tot, scanf("%lld", &a); while (a);
        for (long long p = 1; p != 65536; p <<= 1)
            for (long long odd = 3; p * odd < 65536; odd += 2)
                while (odd * p < 65536 && cnt[odd * p]--)
                    printf("%lld%c", p * odd, --tot ? ' ' : '\n');
        for (long long p = 32768; p; p >>= 1)
            while (cnt[p]--) printf("%lld%c", p, --tot ? ' ' : '\n');
    }
    return 0;
}
