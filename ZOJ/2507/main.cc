#include <iostream>
using namespace std;

int t, n, a;

int main() {
  for (cin >> t; t; --t) {
    int sum = 0, ade = 0;
    for (cin >> n; n; --n) {
      cin >> a;
      sum ^= a;
      ade |= a > 1;
    }
    cout << 2 - (!sum ^ ade) << '\n';
  }
}
