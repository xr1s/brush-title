#include <iostream>
using namespace std;

int T, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    cin >> n;
    int sum = 0;
    for (int i = 0; i != n; ++i) {
      int M, L; cin >> M >> L;
      sum ^= M % (L + 1);
    }
    cout << (sum ? "No\n" : "Yes\n");
  }
}
