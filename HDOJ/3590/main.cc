#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int N, m;
vector<int> g[105];

int sg(int root, int parent) {
  int sum = 0;
  for (int child: g[root])
    if (child != parent)
      sum ^= sg(child, root) + 1;
  return sum;
}

int main() {
  while (cin >> N) {
    int ade = 0, sum = 0;
    while (N--) {
      cin >> m;
      for_each(g, g + m, mem_fn(&vector<int>::clear));
      for (int i = 1; i != m; ++i) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
      }
      int sub = sg(0, -1);
      sum ^= sub;
      ade |= sub > 1;
    }
    cout << (!sum ^ ade ? "PP\n" : "QQ\n");
  }
}
