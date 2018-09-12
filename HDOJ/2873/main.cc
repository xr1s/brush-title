#include <cstring>
#include <iostream>
using namespace std;

int mem[51][51];

int sg(int p, int q) {
  if (mem[p][q] != -1) return mem[p][q];
  bool mex[512]{false};
  if (p != 1 && q != 1)
    for (int i = 1; i != p; ++i)
      for (int j = 1; j != q; ++j)
        mex[sg(p - i, q) ^ sg(p, q - j)] = true;
  else if (p == 1)
    for (int j = 1; j != q; ++j)
      mex[sg(p, q - j)] = true;
  else if (q == 1)
    for (int i = 1; i != p; ++i)
      mex[sg(p - i, q)] = true;
  else return 0;
  for (int i = 0; ; ++i)
    if (!mex[i]) return mem[p][q] = i;
}

int n, m;
char bomb;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  memset(mem, 0xff, sizeof mem);
  while (cin >> n >> m && (n || m)) {
    int sum = 0;
    for (int p = 1; p <= n; ++p)
      for (int q = 1; q <= m; ++q) {
        cin >> bomb;
        if (bomb == '#')
          sum ^= sg(p, q);
      }
    cout << (sum ? "John\n" : "Jack\n");
  }
}
