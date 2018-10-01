#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cout << fixed << setprecision(10);
  double L, f;
  while (cin >> L >> f && (L || f)) {
    const double v = sqrt(2 * L * f);
    const double n = 3600 * v / (L + v * v / (2 * f));
    cout << v << ' ' << n << '\n';
  }
}
