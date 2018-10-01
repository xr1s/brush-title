#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct state {
  int total, cover;
};

bool operator<(const state &lhs, const state &rhs) {
  return lhs.total < rhs.total
      || (lhs.total == rhs.total && lhs.cover > rhs.cover);
}

state operator+(const state &lhs, const state &rhs) {
  return {lhs.total + rhs.total, lhs.cover + rhs.cover};
}

state &operator+=(state &lhs, const state &rhs) {
  return lhs = lhs + rhs;
}

int T, n, m;
vector<int> g[1005];
state stat[1005][2], result;
bool vis[1005];

void treedp(int root, int parent) {
  vis[root] = true;
  stat[root][0] = {0, 0};
  stat[root][1] = {1, 0};
  for (int child: g[root])
    if (child != parent)
      treedp(child, root);
  for (int child: g[root])
    if (child != parent) {
      stat[root][0] += stat[child][1];
      if (stat[child][0] < stat[child][1])
        stat[root][1] += stat[child][0];
      else
        stat[root][1] += stat[child][1], ++stat[root][1].cover;
    }
}

int main() {
  for (cin >> T; T; --T) {
    memset(stat, 0, sizeof stat);
    memset(vis, 0, sizeof vis);
    result = {};
    cin >> n >> m;
    for_each(g, g + n, mem_fn(&vector<int>::clear));
    for (int i = 0; i != m; ++i) {
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i != n; ++i)
      if (!vis[i]) {
        treedp(i, -1);
        result += min(stat[i][0], stat[i][1]);
      }
    cout << result.total << ' '
         << result.cover << ' '
         << m - result.cover << '\n';
  }
}
