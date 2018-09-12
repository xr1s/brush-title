#include <cmath>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  const double phi = (1 + sqrt(5)) / 2;
  long long m, n;
  while (cin >> m >> n) {
    if (m == 0 && n == 0) break;
    bool ollie = false;
    ollie |= m < n && n <= floor(phi * m);
    ollie |= n < m && m <= floor(phi * n);
    cout << (const char *[]){"Stan", "Ollie"}[ollie] << " wins\n";
  }
}
