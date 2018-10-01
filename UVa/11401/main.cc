#include <iostream>
using namespace  std;

int n;
long long a[1000005];

int main() {
  for (long long i = 1; i <= 1000000; ++i)
    a[i] = a[i - 1] + (i - 2 >> 1) * (i - 1 >> 1);
  while (cin >> n && n >= 3) cout << a[n] << '\n';
}
