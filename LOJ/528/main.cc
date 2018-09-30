#include <bitset>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template <size_t N> void
sieve(int mobius[]) {
  vector<int> prime;
  prime.reserve(78498);
  bitset<N> is_comp;
  mobius[1] = 1;
  for (int p = 2; p < N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (int64_t q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        mobius[p * q] = 0;
        break;
      } else mobius[p * q] = -mobius[p];
    }
  }
}

constexpr int maxn = 3162278;
constexpr int mod = 998244353;

long long N, M;
int mobi[maxn];

int solve(long long n, long long m) {
  const int upper = sqrt(min(m, n));
  int r = 0;
  for (int i = 1, j; i <= upper; i = j + 1) {
    j = min(n / (n / i), m / (m / i));
    int sum = mobi[j] - mobi[i - 1];
    if (sum < 0) sum += mod;
    int prod = sum;
    prod = n / ((long long)i * i) % mod * prod % mod;
    prod = m / ((long long)i * i) % mod * prod % mod;
    r += prod;
    if (r >= mod) r -= mod;
  }
  return r;
}

int main() {
  sieve<maxn>(mobi);
  for (int i = 1; i != maxn; ++i) {
    mobi[i] += mobi[i - 1];
    if (mobi[i] >= mod) mobi[i] -= mod;
    else if (mobi[i] < 0) mobi[i] += mod;
  }
  cin >> N >> M;
  cout << solve(N, M) << '\n';
}
