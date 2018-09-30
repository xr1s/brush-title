#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

constexpr int maxn = 50001;

template <size_t N> void
sieve(int mobius[]) {
  vector<int> prime;
  bitset<N> is_comp;
  mobius[1] = 1;
  for (long p = 2; p < N; ++p) {
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
}

int mobius[maxn];
int n, a, b, c, d, k;

long solve(int m, int n) {
  long r = 0;
  for (int i = 1, j; i <= min(m, n); i = j + 1) {
    j = min(m / (m / i), n / (n / i));
    r += (long)(mobius[j] - mobius[i - 1]) * (n / i) * (m / i);
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  sieve<maxn>(mobius);
  partial_sum(mobius, mobius + maxn, mobius);

  for (cin >> n; n; --n) {
    cin >> a >> b >> c >> d >> k;
    cout << solve(b / k, d / k)
          - solve((a - 1) / k, d / k)
          - solve(b / k, (c - 1) / k)
          + solve((a - 1) / k, (c - 1) / k) << '\n';
  }
}
