#include <iostream>
using namespace std;

int T, N, V[25];
int cw, wc;
bool zero;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    cin >> N;
    for (int i = 0; i != N; ++i) cin >> V[i];
    bool zero = false;
    for (int i = 0; i != N; ++i) zero |= V[i] == 0;
    if (zero) {
      for (cw = 0; V[cw]; ++cw);
      for (wc = 0; V[N - wc - 1]; ++wc);
      cout << (cw % 2 || wc % 2 ? "YES\n" : "NO\n");
    } else cout << (N % 2 ? "NO\n" : "YES\n");
  }
}
