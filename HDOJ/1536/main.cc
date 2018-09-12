#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int k, s[105], m, l, h[105];
int mem[10005];

int sg(int h) {
  if (mem[h] != -1) return mem[h];
  bool mex[105]{false};
  for (int i = 0; i != k; ++i)
    if (h - s[i] >= 0) mex[sg(h - s[i])] = true;
  for (int i = 0; ; ++i)
    if (!mex[i]) return mem[h] = i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (cin >> k && k) {
    fill(begin(mem), end(mem), -1);
    for (int i = 0; i != k; ++i) cin >> s[i];
    for (cin >> m; m; --m) {
      int s = 0;
      for (cin >> l; l; --l) {
        cin >> h[l]; s ^= sg(h[l]);
      }
      cout.put(s ? 'W' : 'L');
    }
    cout.put('\n');
  }
}
