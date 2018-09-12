#include <algorithm>
#include <iostream>
using namespace std;

long long lower[10], upper[10];
size_t size = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  lower[0] = -1, upper[0] = 0;
  lower[1] = 9, upper[1] = 18;
  while (upper[size++] < 4294967295) {
    lower[size] = lower[size - 1] * 18;
    upper[size] = upper[size - 1] * 18;
  }

  unsigned n;
  while (cin >> n) {
    auto l = lower_bound(lower, lower + size, n) - lower;
    auto r = lower_bound(upper, upper + size, n) - upper;
    cout << ((const char *[]){"Ollie", "Stan"}[l == r]) << " wins.\n";
  }
}
