#include <iostream>
#include <limits>
using namespace std;

int N, S;
int a[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (cin >> N >> S) {
    for (int i = 0; i != N; ++i) cin >> a[i];
    int mini = numeric_limits<decltype(mini)>::max();
    for (int s = 0, l = 0, r = 0; l != N; s -= a[l++]) {
      while (s < S && r != N) s += a[r++];
      if (s >= S && r - l < mini) mini = r - l;
    }
    cout << (mini == numeric_limits<decltype(mini)>::max() ? 0 : mini);
    cout.put('\n');
  }
}
