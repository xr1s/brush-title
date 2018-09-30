#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

template <long long N> void
sieve(long long mobius[]) {
  typedef vector<long long>::iterator vllit;
  vector<long long> prime;
  bitset<N> composite;
  mobius[1] = 1;
  for (long long p = 2; p < N; ++p) {
    if (!composite.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (vllit q = prime.begin(); q != prime.end(); ++q) {
      if (p * *q >= N) break;
      composite.set(p * *q);
      if (p % *q == 0) {
        mobius[p * *q] = 0;
        break;
      } else mobius[p * *q] = -mobius[p];
    }
  }
}

long long mobius[50005];
int n, a, b, d;

long long f(int m, int n) {
  long long r = 0;
  for (int l = 1, u; l <= min(m, n); l = u + 1) {
    u = min(m / (m / l), n / (n / l));
    r += (mobius[u] - mobius[l - 1]) * (n / l) * (m / l);
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  sieve<50001>(mobius);

  for (int i = 1; i <= 50000; ++i)
    mobius[i] = mobius[i] + mobius[i - 1];

  for (cin >> n; n; --n) {
    cin >> a >> b >> d;
    cout << f(a / d, b / d) << '\n';
  }
}
