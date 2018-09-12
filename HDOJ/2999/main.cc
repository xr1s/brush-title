#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int N, a[100], M, K;
int mem[1001];

int sg(int k) {
  if (mem[k] != -1) return mem[k];
  bool mex[1024]{false};
  for (int i = 0; i != N; ++i)
    for (int j = 0; j <= k - a[i] >> 1; ++j)
      mex[sg(j) ^ sg(k - j - a[i])] = true;
  for (int i = 0; ; ++i)
    if (!mex[i]) return mem[k] = i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  while (cin >> N) {
    memset(mem, 0xff, sizeof mem);
    for (int i = 0; i != N; ++i) cin >> a[i];
    sort(a, a + N); N = unique(a, a + N) - a;
    for (cin >> M; M; --M) {
      cin >> K;
      cout << 2 - !!sg(K) << '\n';
    }
  }
}
