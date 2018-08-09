#include <cstdint>
#include <iostream>
#include <limits>
using namespace std;

int T, A, B, C;
int_fast64_t gar[25][25][25];

void init() {
  cin >> A >> B >> C;
  for (int i = 1; i <= A; ++i)
    for (int j = 1; j <= B; ++j)
      for (int k = 1; k <= C; ++k) {
        cin >> gar[i][j][k];
        gar[i][j][k] += gar[i - 1][j][k];
        gar[i][j][k] += gar[i][j - 1][k];
        gar[i][j][k] -= gar[i - 1][j - 1][k];
      }
}

void work() {
  int_fast64_t answer = numeric_limits<decltype(answer)>::min();
  for (int s = 1; s <= A; ++s)
    for (int n = 1; n <= s; ++n)
      for (int e = 1; e <= B; ++e)
        for (int w = 1; w <= e; ++w) {
          int_fast64_t pre = 0;
          for (int k = 1; k <= C; ++k) {
            int_fast64_t sum = gar[s][e][k];
            sum -= gar[n - 1][e][k];
            sum -= gar[s][w - 1][k];
            sum += gar[n - 1][w - 1][k];
            pre += sum;
            if (pre > answer) answer = pre;
            if (pre < 0) pre = 0;
          }
        }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    init();
    work();
    if (T > 1) cout << '\n';
  }
}
