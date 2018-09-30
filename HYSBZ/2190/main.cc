#include <numeric>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

template <int N> void
sieve(int mobius[]) {
  typedef vector<int>::iterator vit;
  vector<int> prime;
  bitset<N> composite;
  mobius[1] = 1;
  for (int p = 2; p < N; ++p) {
    if (!composite.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (vit q = prime.begin(); q != prime.end(); ++q) {
      if (p * *q >= N) break;
      composite.set(p * *q);
      if (p % *q == 0) {
        mobius[p * *q] = 0;
        break;
      } else mobius[p * *q] = -mobius[p];
    }
  }
}

int mobius[40001];
int n, a, b, d;

int solve(int n) {
  int r = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    r += (mobius[j] - mobius[i - 1]) * (n / i) * (n / i);
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  sieve<40001>(mobius);
  partial_sum(mobius, mobius + 40001, mobius);

  cin >> n;
  cout << solve(n - 1) + 2 << '\n';
}
