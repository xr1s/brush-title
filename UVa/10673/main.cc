#include <cassert>
#include <iostream>
using namespace std;

int T, x, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  for (cin >> T; T; --T) {
    cin >> x >> k;
    const int m = x % k;
    cout << k - m << ' ' << m << '\n';
  }
}
