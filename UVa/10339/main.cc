#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int k, m;

int main() {
  while (cin >> k >> m) {
    double s = 43200. / abs(k - m) * (86400 - k);
    int hh = (int)(s / 3600 - 1) % 12 + 1;
    int mm = (int)(s / 60) % 60;
    int ss = (int)s % 60;
    if (ss >= 30) ++mm, ss = 0;
    if (mm == 60) ++hh, mm = 0;
    if (hh == 13) hh = 1;
    cout << k << ' ' << m << ' '
         << setfill('0') << setw(2) << hh << ':'
         << setfill('0') << setw(2) << mm << '\n';
  }
}
