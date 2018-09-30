#include <bitset>
#include <iostream>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <vector>
using namespace std;
using namespace __gnu_pbds;

template <size_t N>
void sieve(long long euler[], int mobius[]) {
  bitset<N> is_comp;
  vector<int> prime;
  euler[1] = mobius[1] = 1;
  for (int p = 2; p != N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
      euler[p] = p - 1;
    }
    for (vector<int>::iterator i = prime.begin(); i != prime.end(); ++i) {
      const int q = *i;
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        euler[p * q] = euler[p] * q;
        mobius[p * q] = 0;
        break;
      } else {
        euler[p * q] = euler[p] * (q - 1);
        mobius[p * q] = -mobius[p];
      }
    }
  }
}

const int maxn = 2000000;

long long phi[maxn];
int mu[maxn];

int mertens(unsigned n) {
  static cc_hash_table<int, int> mem;
  if (n < maxn) return mu[n];
  cc_hash_table<int, int>::point_iterator m;
  if ((m = mem.find(n)) != mem.end())
    return m->second;
  int r = 1;
  for (unsigned i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    r -= (j - i + 1) * mertens(n / i);
  }
  return mem[n] = r;
}

long long totient(unsigned n) {
  static cc_hash_table<int, long long> mem;
  if (n < maxn) return phi[n];
  cc_hash_table<int, long long>::point_iterator p;
  if ((p = mem.find(n)) != mem.end())
    return p->second;
  long long r = n * (n + 1LL) / 2;
  for (unsigned i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    r -= (j - i + 1) * totient(n / i);
  }
  return mem[n] = r;
}

int T, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  sieve<maxn>(phi, mu);
  partial_sum(phi, phi + maxn, phi);
  partial_sum(mu, mu + maxn, mu);

  for (cin >> T; T; --T) {
    cin >> N;
    cout << totient(N) << ' '
         << mertens(N) << '\n';
  }
}
