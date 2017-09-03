#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool is_prime[1000005];
vector<int> prime;
long long euler[1000005];

int sieve(int n) {
    memset(is_prime, 0x01, sizeof is_prime);
    is_prime[0] = is_prime[1] = false; euler[1] = 1;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            prime.push_back(p);
            euler[p] = p - 1;
        }
        for (int q: prime) {
            if (p * q > n) break;
            is_prime[p * q] = false;
            if (p % q == 0) {
                euler[p * q] = euler[p] * q;
                break;
            }
            euler[p * q] = euler[p] * (q - 1);
        }
    }
}

int n;

int main() {
    sieve(1000000);
    euler[0] = -1;
    for (int i = 1; i <= 1000000; ++i)
        euler[i] += euler[i - 1];
    for (scanf("%d", &n); n; scanf("%d", &n))
        printf("%lld\n", euler[n]);
    return 0;
}
