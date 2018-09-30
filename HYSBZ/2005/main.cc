#include <numeric>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

template <int N> void
sieve(int euler[]) {
  vector<int> prime;
  bitset<N> is_comp;
  euler[1] = 1;
  for (int p = 2; p < N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      euler[p] = p - 1;
    }
    for (vector<int>::iterator i = prime.begin(); i != prime.end(); ++i) {
      const int q = *i;
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        euler[p * q] = euler[p] * q;
        break;
      } else euler[p * q] = euler[p] * (q - 1);
    }
  }
}

int euler[100005];

long long solve(long long n, long long m) {
  long long r = 0;
  for (int i = 1, j; i <= min(n, m); i = j + 1) {
    j = min(n / (n / i), m / (m / i));
    r += (euler[j] - euler[i - 1]) * (n / i) * (m / i);
  }
  return r * 2 - m * n;
}

int n, m;

int main() {
  sieve<100001>(euler);
  partial_sum(euler, euler + 100001, euler);
  cin >> n >> m;
  cout << solve(n, m) << '\n';
}
