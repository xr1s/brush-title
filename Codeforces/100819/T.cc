#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tri[2][3];

int main() {
    for (int i = 0; i != 2; ++i) {
        for (int j = 0; j != 3; ++j)
            scanf("%d", &tri[i][j]);
        sort(tri[i], tri[i] + 3);
    }
    if (!memcmp(tri[0], tri[1], sizeof *tri))
        if (tri[0][0] * tri[1][0] + tri[0][1] * tri[1][1] == tri[0][2] * tri[1][2]) {
            puts("YES");
            return 0;
        }
    puts("NO");
    return 0;
}
