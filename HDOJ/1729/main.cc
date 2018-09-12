#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int T, N, s, c;

void prep() {
  int i = 0;
  do ++i, m[i * i + i] = i - 1;
  while (i * i + i <= 1000000);
  m[0] = -1;
}

int sg(int s, int c) {
  int t = m.lower_bound(s)->second;
  while (t >= c)
    s = t, t = m.lower_bound(s)->second;
  return s - c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  prep();

  while (cin >> N && N) {
    int sum = 0;
    for (int i = 0; i != N; ++i) {
      cin >> s >> c; sum ^= sg(s, c);
    }
    cout << "Case " << ++T << ":\n";
    cout << (sum ? "Yes\n" : "No\n");
  }
}
