#include <iostream>
#include <iomanip>
using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cout << fixed << setprecision(5);
  while (cin >> n >> m) {
    double len = 0;
    for (int i = 0, j = 0; i != n; ++i) {
      const double orig = 1e4 * i / n;
      while (1e4 * (j + 1) / (n + m) < orig) ++j;
      const double l = orig - 1e4 * j / (n + m);
      const double r = orig - 1e4 * (j + 1) / (n + m);
      len += min(abs(l), abs(r));
    }
    cout << len << '\n';
  }
}
