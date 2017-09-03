#include <cstdio>
using namespace std;

const long long mod = 10007;
long long T, N;

template <typename integer>
integer power(integer a, integer n, integer m) {
    integer r = 1;
    do {
        if (n & 1) (r *= a) %= m;
        if (n ^ 1) (a *= a) %= m;
    } while (n >>= 1);
    return r;
}

int main() {
    for (scanf("%lld", &T); T; --T) {
        scanf("%lld", &N);
        long long p = power(2ll, N - 1, mod);
        printf("%lld\n", p * (p + 1) % mod);
    }
    return 0;
}
