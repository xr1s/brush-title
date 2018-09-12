#include <iostream>
using namespace std;

uint64_t sg(uint64_t n) {
  while (n & 1) n >>= 1;
  return n >> 1;
}

uint64_t T, N, A;

int main() {
  for (cin >> T; T; --T) {
    uint64_t S = 0;
    for (cin >> N; N; --N)
      cin >> A, (void)(S ^= sg(A));
    cout << (S ? "YES\n" : "NO\n");
  }
}
