#include <iostream>
using namespace std;

template <typename B, typename E>
B modpow(B base, E expo, B mod) {
  B retn = 1;
  do {
    if (expo & 1) retn = retn * base % mod;
    if (expo ^ 1) base = base * base % mod;
  } while (expo >>= 1);
  return retn;
}

constexpr long long mod = 1000000007LL;
int T, N;

int main() {
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    cin >> N;
    cout << "Case #" << cs << ": "
         << modpow(2LL, N - 1, mod) * N % mod << '\n';
  }
}
