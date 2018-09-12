#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> roots, childs[1005];

int sg(int node) {
  int sum = 0;
  for (int chld: childs[node])
    sum ^= sg(chld) + 1;
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  while (cin >> N) {
    for_each(childs, childs + N, mem_fn(&vector<int>::clear));
    roots = vector<int>{};
    for (int i = 0; i != N; ++i) {
      int par; cin >> par;
      if (par == -1) roots.push_back(i);
      else childs[par].push_back(i);
    }
    int sum = 0;
    for (int root: roots)
      sum ^= sg(root);
    cout << (sum ? "YES\n" : "NO\n");
  }
}
