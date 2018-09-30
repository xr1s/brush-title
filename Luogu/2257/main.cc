#include <cstdint>
#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

constexpr int maxn = 10000001;
int mobius[maxn];
int64_t let[maxn];

template <size_t N> vector<int>
 sieve(int mobius[]) {
  vector<int> prime;
  bitset<N> is_comp;
  mobius[1] = 1;
  for (int p = 2; p != N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (int q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        mobius[p * q] = 0;
        break;
      } else mobius[p * q] = -mobius[p];
    }
  }
  return prime;
}

int T, n, m;

int solve(int n, int m) {
  int64_t r = 0;
  for (int i = 1, j; i <= min(n, m); i = j + 1) {
    j = min(n / (n / i), m / (m / i));
    r += (let[j] - let[i - 1]) * (n / i) * (m / i);
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  vector<int> prime = sieve<maxn>(mobius);
  for (int p: prime)
    for (int q = 1; p * q < maxn; ++q)
      let[p * q] += mobius[q];
  partial_sum(let, let + maxn, let);

  for (cin >> T; T; --T) {
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
}
