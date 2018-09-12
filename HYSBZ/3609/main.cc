#include <iostream>
using namespace std;

bool sg(int n, int m) {
  return n + (n - 1) / m & 1;
}

int T, n, m;

int main() {
  for (cin >> T; T; --T) {
    cin >> n >> m;
    cout << sg(n, m) << '\n';
  }
}
