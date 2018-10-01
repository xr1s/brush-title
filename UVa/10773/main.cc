#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int T;
double d, v, u;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cout << fixed << setprecision(3);
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    cin >> d >> v >> u;
    if (v == 0 || u <= v) {
      cout << "Case " << cs
           << ": can't determine\n";
      continue;
    }
    const double fast = d / u;
    const double near = d / sqrt(u * u - v * v);
    cout << "Case " << cs << ": "
         << near - fast << '\n';
  }
}
