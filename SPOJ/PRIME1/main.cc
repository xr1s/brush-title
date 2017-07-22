#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int64_t> seg_sieve(const int64_t n) {
    const size_t part = (size_t)sqrt(n);
    int64_t iter = 3, p = 3;

    bool *is_prime = new bool[part];
    memset(is_prime, true, part);
    // Sieve of Eratosthenes
    for (size_t i = 2; i <= part; ++i) if (is_prime[i])
        for (size_t j = i << 1; j <= part; j += i) is_prime[j] = false;

    bool *sieve = new bool[part];
    vector<int64_t> subp, next, prime = {2};

    for (int64_t l = 0; l <= n; l += part) {
        memset(sieve, true, part);
        int64_t r = l + part - 1;
        if (r > n) r = n;
        for (; iter * iter <= r; iter += 2)
            if (is_prime[iter]) {
                subp.push_back(iter);
                next.push_back(iter * iter - l);
            }
        for (size_t i = 0; i != subp.size(); ++i) {
            int64_t p2 = subp[i] << 1, nxt = next[i];
            for (; nxt < part; nxt += p2) sieve[nxt] = false;
            next[i] = nxt - part;
        }
        for (; p <= r; p += 2)
            if (sieve[p - l]) prime.push_back(p);
    }
    return prime;
}

int t, n, m;

int main() {
    vector<int64_t> prime = seg_sieve(1000000000);
    for (scanf("%d", &t); t; --t) {
        scanf("%d%d", &n, &m);
        auto l = lower_bound(prime.begin(), prime.end(), n);
        auto r = upper_bound(prime.begin(), prime.end(), m);
        for (auto it = l; it != r; ++it) printf("%li\n", *it);
        putchar('\n');
    }
    return 0;
}
