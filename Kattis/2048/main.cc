#include <cstdio>
using namespace std;

int grid[6][6];
int dir;

int main() {
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            scanf("%d", &grid[i][j]);
    scanf("%d", &dir);
    switch (dir) {
        case 0:  // left
            for (int i = 1; i <= 4; ++i) {
                for (int j = 1; j <= 4;) {
                    int k = j + 1;
                    while (!grid[i][k] && k <= 4) ++k;
                    if (grid[i][j] == grid[i][k])
                        grid[i][j] <<= 1, grid[i][k] = 0;
                    j = k;
                }
                int l = 1;
                for (int j = 1; j <= 4; ++j)
                    if (grid[i][j]) grid[i][l++] = grid[i][j];
                for (; l <= 4; ++l) grid[i][l] = 0;
            }
            break;
        case 1:  // up
            for (int j = 1; j <= 4; ++j) {
                for (int i = 1; i <= 4;) {
                    int k = i + 1;
                    while (!grid[k][j] && k <= 4) ++k;
                    if (grid[i][j] == grid[k][j])
                        grid[i][j] <<= 1, grid[k][j] = 0;
                    i = k;
                }
                int u = 1;
                for (int i = 1; i <= 4; ++i)
                    if (grid[i][j]) grid[u++][j] = grid[i][j];
                for (; u <= 4; ++u) grid[u][j] = 0;
            }
            break;
        case 2:  // right
            for (int i = 1; i <= 4; ++i) {
                for (int j = 4; j;) {
                    int k = j - 1;
                    while (!grid[i][k] && k) --k;
                    if (grid[i][j] == grid[i][k])
                        grid[i][j] <<= 1, grid[i][k] = 0;
                    j = k;
                }
                int r = 4;
                for (int j = 4; j; --j)
                    if (grid[i][j]) grid[i][r--] = grid[i][j];
                for (; r; --r) grid[i][r] = 0;
            }
            break;
        case 3:  // down
            for (int j = 1; j <= 4; ++j) {
                for (int i = 4; i;) {
                    int k = i - 1;
                    while (!grid[k][j] && k) --k;
                    if (grid[i][j] == grid[k][j])
                        grid[i][j] <<= 1, grid[k][j] = 0;
                    i = k;
                }
                int d = 4;
                for (int i = 4; i; --i)
                    if (grid[i][j]) grid[d--][j] = grid[i][j];
                for (; d; --d) grid[d][j] = 0;
            }
            break;
    }
    for (int i = 1; i <= 4; ++i) {
        printf("%d", grid[i][1]);
        for (int j = 2; j <= 4; ++j)
            printf(" %d", grid[i][j]);
        putchar('\n');
    }
    return 0;
}
