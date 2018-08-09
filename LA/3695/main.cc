#include <algorithm>
#include <iostream>
using namespace std;

int T, N, x[105], y[105];
int xcnt, ycnt;
pair<int, int> coor[105];
int grid[105][105];
int pre[105][105][4], sum[105][2];

bool init() {
  ++T;
  cin >> N;
  if (N == 0) return false;
  for (int i = 0; i != N; ++i) {
    cin >> coor[i].first >> coor[i].second;
    x[i] = coor[i].first; y[i] = coor[i].second;
  }
  sort(x, x + N); xcnt = unique(x, x + N) - x;
  sort(y, y + N); ycnt = unique(y, y + N) - y;

  if (xcnt == 1 || ycnt == 1) return true;

  fill(*grid, *1[&grid], 0);
  for (int i = 0; i != N; ++i) {
    const int xi = lower_bound(x, x + xcnt, coor[i].first) - x;
    const int yi = lower_bound(y, y + ycnt, coor[i].second) - y;
    ++grid[xi + 1][yi + 1];
  }

  fill(**pre, **1[&pre], 0);
  for (int i = 1; i <= xcnt; ++i)
    for (int j = 1; j <= ycnt; ++j) {
      pre[i][j][0] = pre[i][j - 1][0] + grid[i][j - 1];
      pre[i][j][1] = pre[i - 1][j][1] + grid[i - 1][j];
    }
  for (int i = xcnt; i >= 1; --i)
    for (int j = ycnt; j >= 1; --j) {
      pre[i][j][2] = pre[i][j + 1][2] + grid[i][j + 1];
      pre[i][j][3] = pre[i + 1][j][3] + grid[i + 1][j];
    }
  for (int i = 1; i <= xcnt; ++i)
    sum[i][0] = pre[i][1][2] + grid[i][1];
  for (int j = 1; j <= ycnt; ++j)
    sum[j][1] = pre[1][j][3] + grid[1][j];

  return true;
}

void work() {
  if (xcnt == 1 || ycnt == 1)
    return (void)(cout << "Case " << T << ": " << N << '\n');

  int answer = 0;
  for (int i = 1; i <= xcnt; ++i)
    for (int j = i + 1; j <= xcnt; ++j) {
      int left = 0;
      for (int k = 1; k <= ycnt; ++k) {
        int right = sum[k][1] - pre[i][k][1] - pre[j][k][3];
        right += pre[i][k][0] + pre[j][k][0];
        right += left;
        if (right > answer) answer = right;
        int now = sum[k][1] - pre[i + 1][k][1] - pre[j - 1][k][3];
        now -= pre[i][k][0] + pre[j][k][0];
        if (now > left) left = now;
      }
    }
  cout << "Case " << T << ": " << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  while (init()) work();
}
