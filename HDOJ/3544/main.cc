#include <algorithm>
#include <iostream>
using namespace std;

int cutcake(int n, int m) {
  while (n != 1 && m != 1)
    n >>= 1, m >>= 1;
  return n - m;
}

int T, N, X, Y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    long long surreal = 0;
    for (cin >> N; N; --N) {
      cin >> X >> Y;
      surreal += cutcake(X, Y);
    }
    cout << "Case " << cs << ": "
         << (surreal > 0 ? "Alice\n": "Bob\n");
  }
}
