#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, X, M, O, P;
vector<int> G[1005];
int SG[1005];

int sg(int Q) {
  if (SG[Q] != -1) return SG[Q];
  unordered_set<int> X;
  for (auto P: G[Q])
    X.insert(sg(P));
  for (int i = 0; ; ++i)
    if (X.find(i) == X.end())
      return SG[Q] = i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (cin >> N) {
    for_each(G, G + N, mem_fn(&vector<int>::clear));
    fill(SG, SG + N, -1);
    for (int i = 0; i != N; ++i)
      for (cin >> X; X; --X) {
        cin >> O; G[i].push_back(O);
      }
    while (cin >> M && M) {
      int S = 0;
      while (M--) {
        cin >> P; S ^= sg(P);
      }
      cout << (S ? "WIN\n" : "LOSE\n");
    }
  }
}
