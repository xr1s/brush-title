#include <vector>
#include <iostream>
using namespace std;

int t, n, k;

vector<int> getPPosition(int n, int k) {
  vector<int> p; p.push_back(0); p.push_back(1);
  for (int i = 0; p.back() < n; ) {
    while (p[i + 1] * k < p.back()) ++i;
    p.push_back(p.back() + p[i + 1]);
  }
  return p;
}

int firstPick(int n, int k) {
  vector<int> p = getPPosition(n, k);
  int pick = -1;
  if (n != p.back())
    for (; n; p.pop_back())
      if (n >= p.back())
        n -= pick = p.back();
  return pick;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> t;
  for (int N = 1; N <= t; ++N) {
    cin >> n >> k;
    int pick = firstPick(n, k);

    cout << "Case " << N << ": ";
    if (pick == -1) cout << "lose\n";
    else cout << pick << '\n';
  }
}
