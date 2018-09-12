#include <iostream>
using namespace std;

int T, N, A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    int sum = 0, ade = 0;
    for (cin >> N; N; --N) {
      cin >> A;
      sum ^= A;
      ade |= A > 1;
    }
    cout << (!sum ^ ade ? "John\n" : "Brother\n");
  }
}
