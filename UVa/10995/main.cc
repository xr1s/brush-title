#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

long long T, n, k;

template <typename T, typename E> T
modpow(T b, E e, T m) {
  T r = 1;
  do {
    if (e & 1) r = r * b % m;
    if (e > 1) b = b * b % m;
  } while (e >>= 1);
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cout << setfill('0');
  for (cin >> T; T; --T) {
    cin >> n >> k;
    const int t = modpow(n, k, 1000LL);
    const int l = pow(10, fmod(k * log10(n), 1)) * 100;
    cout << setw(0) << l << "..." << setw(3) << t << '\n';
  }
}
