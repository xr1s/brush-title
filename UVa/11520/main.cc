#include <cstring>
#include <iostream>
using namespace std;

int T, n, kase;
char grid[16][16];

void init() {
  static int T = 0;
  memset(grid, '.', sizeof grid);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> grid[i][j];
  cout << "Case " << ++T << ":\n";
}

bool check(int i, int j, char c) {
  return grid[i - 1][j] != c
      && grid[i][j - 1] != c
      && grid[i + 1][j] != c
      && grid[i][j + 1] != c;
}

void work() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      if (grid[i][j] == '.') {
        for (int c = 'A'; c <= 'Z'; ++c)
          if (check(i, j, c)) {
            cout.put(grid[i][j] = c);
            break;
          }
      } else cout.put(grid[i][j]);
    cout.put('\n');
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> T; T; --T) {
    init(), work();
  }
}
