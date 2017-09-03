#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T, R, C, matrix[305][305];
int maxlen;
 
bool is_magic(int d, int u, int l, int  r, int len) {
    if (matrix[u][r] - matrix[u][l - 1] - matrix[u - 1][r] + matrix[u - 1][l - 1] != len)
        return false;
    if (matrix[d][r] - matrix[d][l - 1] - matrix[d - 1][r] + matrix[d - 1][l - 1] != len)
        return false;
    if (matrix[u][r] - matrix[u][r - 1] - matrix[d - 1][r] + matrix[d - 1][r - 1] != len)
        return false;
    if (matrix[u][l] - matrix[u][l - 1] - matrix[d - 1][l] + matrix[d - 1][l - 1] != len)
        return false;
    int white = matrix[u][r] - matrix[u][l - 1] - matrix[d - 1][r] + matrix[d - 1][l - 1] - len * 4 + 4;
    len -= 2;
    if (white != len * len + 1 >> 1 && white != len * len >> 1) return false;
    return true;
}

void print_matrix() {
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            printf("%d ", matrix[r][c]);
        }
        putchar('\n');
    }
}

int main() {
    for (scanf("%d", &T); T; --T) {
        memset(matrix, 0, sizeof matrix);
        scanf("%d%d", &R, &C);
        for (int r = 1; r <= R; ++r)
            for (int c = 1; c <= C; ++c) {
                scanf("%d", &matrix[r][c]);
            }
        for (int r = 1; r <= R; ++r)
            for (int c = 1; c <= C; ++c)
                matrix[r][c] += matrix[r - 1][c] + matrix[r][c - 1] - matrix[r - 1][c - 1];
        int maxlen = max(R, C), answer = 0;
        for (int len = 1; len != maxlen; ++len)
            for (int r = 1; r <= R - len; ++r)
                for (int c = 1; c <= C - len; ++c)
                    answer += is_magic(r, r + len, c, c + len, len + 1);
        printf("%d\n", answer);
    }
    return 0;
}
