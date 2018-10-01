#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<pair<T, int>> factorize(T n) {
  vector<pair<T, int>> factor;
  for (T p{2}; p * p <= n; ++p)
    if (n % p == 0) {
      int r = 0;
      do ++r, n /= p;
      while (n % p == 0);
      factor.emplace_back(p, r);
    }
  if (n != 1)
    factor.emplace_back(n, 1);
  return factor;
}

int N;

int main() {
  while (cin >> N && N) {
    auto factor = factorize(N);
    long long total = 1;
    for (const auto &pr: factor)
      total *= 2 * pr.second + 1;
    cout << N << ' ' << (total + 1) / 2 << '\n';
  }
}
