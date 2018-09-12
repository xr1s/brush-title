#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, N, I, J;
vector<int> g[100005];

int sg(int node, int parent) {
  int sum = 0;
  for (auto child: g[node])
    if (child != parent)
      sum ^= sg(child, node) + 1;
  return sum;
}

int main() {
  for (cin >> T; T; --T) {
    cin >> N;
    for_each(g, g + N, mem_fn(&vector<int>::clear));
    for (int i = 1; i != N; ++i) {
      cin >> I >> J;
      g[I - 1].push_back(J - 1);
      g[J - 1].push_back(I - 1);
    }
    cout << (sg(0, -1) ? "Alice\n" : "Bob\n");
  }
}
