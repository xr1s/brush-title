#include <iostream>
using namespace std;

template <typename T>
T gcd(T m, T n) {
  if (!m || !n) return m | n;
  if (m < 0) m = -m;
  if (n < 0) n = -n;
  int p = 0;
  while (!(m & 1) && !(n & 1))
    m >>= 1, n >>= 1, ++p;
  while (n) {
    while (!(m & 1)) m >>= 1;
    while (!(n & 1)) n >>= 1;
    if (m >= n) std::swap(m, n);
    n = (n - m) >> 1;
  }
  return m << p;
}

int T, A, C;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    cin >> A >> C;
    if (C % A == 0) {
      int B = C / A, G = gcd(A, B);
      while (G != 1) {
        A /= G; B *= G;
        G = gcd(A, B);
      }
      cout << B << '\n';
    } else cout << "NO SOLUTION\n";
  }
}
