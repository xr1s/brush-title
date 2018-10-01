#include <iostream>
using namespace std;

int T, n;

int main() {
  for (cin >> T; T; --T) {
    cin >> n;
    const int l = n / 2, r = n - n / 2;
    cout << (l * (l - 1) + r * (r - 1)) / 2 << '\n';
  }
}
