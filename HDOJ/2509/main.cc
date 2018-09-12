#include <iostream>
using namespace std;

int n, a;

int main() {
  while (cin >> n) {
    int sum = 0, ade = 0;
    for (int i = 0; i != n; ++i) {
      cin >> a;
      sum ^= a;
      ade |= a > 1;
    }
    cout << (!sum ^ ade ? "Yes\n" : "No\n");
  }
}
