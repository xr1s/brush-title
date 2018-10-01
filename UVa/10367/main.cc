#include <iostream>
using namespace std;

int n, k, a[10005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  while (cin >> n >> k) {
    if (n == -1 && k == -1) return 0;
    for (int i = 0; i <= n; ++i) cin >> a[i];
    for (int i = n + 1; i <= k; ++i) a[i] = 0;
    if (k == 0) {
      cout << "0\n";
      continue;
    }
    for (int i = n; i >= k; --i) a[i - k] -= a[i];
    while (k > 1 && a[k - 1] == 0) --k;
    for (int i = 0; i != k; ++i)
      cout << a[i] << " \n"[i == k - 1];
  }
}
