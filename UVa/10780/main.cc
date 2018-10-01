#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

template <size_t N>
vector<int> sieve() {
  bitset<N> is_comp;
  vector<int> prime;
  for (int p = 2; p != N; ++p) {
    if (!is_comp.test(p))
      prime.push_back(p);
    for (int q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) break;
    }
  }
  return prime;
}

const vector<int> prime = sieve<5001>();

int T, n, m;

int main() {
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    cout << "Case " << cs << ":\n";
    cin >> m >> n;
    int ans = ~0U >> 1;
    for (int p: prime)
      if (m % p == 0) {
        int e = 0, r = 0;
        for (int q = p; q < n; )
          r += n / q, q *= p;
        do m /= p, ++e;
        while (m % p == 0);
        ans = min(ans, r / e);
      } else if (p > m) break;
    if (ans) cout << ans << '\n';
    else cout << "Impossible to divide\n";
  }
}
