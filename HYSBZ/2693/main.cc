#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 100000009;

int ps[10000005];

template <int N> void
sieve(int ps[]) {
  vector<int> prime;
  bitset<N> is_comp;
  ps[1] = 1;
  for (long p = 2; p < N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      ps[p] = p % mod - p * p % mod;
      if (ps[p] < 0) ps[p] += mod;
    }
    for (vector<int>::iterator i = prime.begin(); i != prime.end(); ++i) {
      const long q = *i;
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        ps[p * q] = ps[p] * q % mod;
        break;
      } else {
        ps[p * q] = (long)ps[p] * ps[q] % mod;
      }
    }
  }
}

int solve(int n, int m) {
  int sum = 0;
  for (int i = 1, j; i <= min(n, m); i = j + 1) {
    const int ni = n / i, mi = m / i;
    const long Sn = ni * (ni + 1L) / 2 % mod;
    const long Sm = mi * (mi + 1L) / 2 % mod;
    j = min(n / ni, m / mi);
    sum += Sn * Sm % mod * (ps[j] - ps[i - 1] + mod) % mod;
    if (sum >= mod) sum -= mod;
  }
  return sum;
}

int T, n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  sieve<10000001>(ps);
  for (int i = 1; i <= 10000000; ++i)
    if ((ps[i] += ps[i - 1]) >= mod) ps[i] -= mod;

  for (cin >> T; T; --T) {
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
}
