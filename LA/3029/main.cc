#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int T, M, N;
char grid[1005][1005];
int h[1005], l[1005], r[1005];
int answer;

void init() {
  cin >> M >> N;
  for (int i = 1; i <= M; ++i)
    for (int j = 1; j <= N; ++j)
      cin >> grid[i][j];

  fill(h, 1[&h], 0);
  fill(l, 1[&l], 1);
  fill(r, 1[&r], N);
  answer = numeric_limits<decltype(answer)>::min();
}

void work() {
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= N; ++j)
      if (grid[i][j] == 'F') ++h[j]; else h[j] = 0;
    int lm = 1, rm = N;
    for (int j = 1; j <= N; ++j)
      if (grid[i][j] == 'F')
        l[j] = max(l[j], lm);
      else l[j] = 1, lm = j + 1;
    for (int j = N; j >= 1; --j)
      if (grid[i][j] == 'F')
        r[j] = min(r[j], rm);
      else r[j] = N, rm = j - 1;
    for (int j = 1; j <= N; ++j)
      answer = max(answer, h[j] * (r[j] - l[j] + 1));
  }
  cout << answer * 3 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  fill(*grid, *1[&grid], 'R');
  for (cin >> T; T; --T) {
    init(); work();
  }
}
