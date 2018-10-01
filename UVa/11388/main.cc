#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int T, G, L;

int main() {
  for (cin >> T; T; --T) {
    cin >> G >> L;
    if (L % G) cout << "-1\n";
    else cout << G << ' ' << L << '\n';
  }
}
