#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
char grid[105][105];
long long area;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(grid, '0', sizeof grid);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            while (!isdigit(grid[i][j] = getchar()));
    for (int i = 1; i <= n + 1; ++i)
        for (int j = 1; j <= m + 1; ++j) {
            area += abs(grid[i][j] - grid[i - 1][j]);
            area += abs(grid[i][j] - grid[i][j - 1]);
            if (grid[i][j] != '0') area += 2;
        }
    printf("%lld\n", area);
    return 0;
}
