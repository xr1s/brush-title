#include <vector>
#include <iostream>
using namespace std;

vector<long long> getPPosition(int n, int k) {
  vector<long long> p{0, 1};
  for (int i = 0; p.back() <= n; ) {
    while (p[i + 1] * k < p.back()) ++i;
    p.push_back(p.back() + p[i + 1]);
  }
  return p;
}

int T, N, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  for (cin >> T; T; --T) {
    cin >> m >> N;
    int n = getPPosition(N, m).size();
    cout << N - n + 2 << '\n';
  }
}
