#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;

int sg(int n) {
  return n && !__builtin_parity(n);
}

int T, n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int sum = 0;
    for (cin >> n; n; --n) {
      cin >> k; sum ^= sg(k);
    }
    cout << "Case " << cs << ": "
         << (sum ? "Yes\n" : "No\n");
  }
}
