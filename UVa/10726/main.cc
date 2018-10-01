#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

long long T, S, M, l, r;

template <typename T, typename E>
T ipow(T base, E expo) {
  T retn = 1;
  do {
    if (expo & 1) retn *= base;
    if (expo > 1) base *= base;
  } while (expo >>= 1);
  return retn;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> T;
  for (long long cs = 1; cs <= T; ++cs) {
    cin >> S >> M >> l >> r;
    if (log2(S - 1) * S > 32) {
      cout << "Case " << cs << ": 0\n";
      continue;
    }
    const long long step = ipow(S - 1, S);
    const long long spow = ipow(S, S);
    long long answer = 0;
    for (long long i = step; ; i += step) {
      const long long R0 = i - M * (S - 1);
      const long long n = i / step * spow - M * (S - 1);
      if (n > r) break;
      if (R0 % S == 0 && l <= n) ++answer;
    }
    cout << "Case " << cs << ": "
         << answer << '\n';
  }
}
