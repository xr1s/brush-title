#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const double pi = acos(-1.);
int N, M, L, R, S[30];

bool win() {
  for (int j = 0, sum = 0; 1 << j <= 100000000; ++j) {
    for (int i = 0; i != N; ++i) sum += S[i] >> j & 1;
    if (sum % (M + 1)) return true;
  }
  return false;
}

int main() {
  while (cin >> N >> M >> L >> R) {
    L = floor(L / (2 * pi * R)) + 1;
    for (int i = 0; i != N; ++i) cin >> S[i];
    for (int i = 0; i != N; ++i)
      S[i] = int(S[i] / (2 * pi * R) + 1) % L;
    cout << (win() ? "Alice\n" : "Bob\n");
  }
}
