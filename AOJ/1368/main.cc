
#include <cstdio>
using namespace std;

int table[10][10];
int check[10][10][10][10][10];

long long error() {
    long long error = 0, count = 0;
    for (int a = 0; a != 10; ++a)
        for (int b = 0; b != 10; ++b)
            for (int c = 0; c != 10; ++c)
                for (int d = 0; d != 10; ++d) {
                    int e = table[table[table[table[0][a]][b]][c]][d];
                    count = 0;
                    for (int wa = 0; wa != 10; ++wa)
                        if (!check[wa][b][c][d][e]) ++count;
                    if (count > 1) {
                        ++error;
                        continue;
                    } else count = 0;
                    for (int wb = 0; wb != 10; ++wb)
                        if (!check[a][wb][c][d][e]) ++count;
                    if (count > 1) {
                        ++error;
                        continue;
                    } else count = 0;
                    for (int wc = 0; wc != 10; ++wc)
                        if (!check[a][b][wc][d][e]) ++count;
                    if (count > 1) {
                        ++error;
                        continue;
                    } else count = 0;
                    for (int wd = 0; wd != 10; ++wd)
                        if (!check[a][b][c][wd][e]) ++count;
                    if (count > 1) {
                        ++error;
                        continue;
                    } else count = 0;
                    for (int we = 0; we != 10; ++we)
                        if (!check[a][b][c][d][we]) ++count;
                    if (count > 1) {
                        ++error;
                        continue;
                    } else count = 0;
                    if (a != b && !check[b][a][c][d][e]) {
                        ++error; continue;
                    }
                    if (b != c && !check[a][c][b][d][e]) {
                        ++error; continue;
                    }
                    if (c != d && !check[a][b][d][c][e]) {
                        ++error; continue;
                    }
                    if (d != e && !check[a][b][c][e][d]) {
                        ++error; continue;
                    }
                }
    return error;
}

int main() {
    for (int i = 0; i != 10; ++i)
        for (int j = 0; j != 10; ++j)
            scanf("%d", &table[i][j]);
    for (int a = 0; a != 10; ++a)
        for (int b = 0; b != 10; ++b)
            for (int c = 0; c != 10; ++c)
                for (int d = 0; d != 10; ++d)
                    for (int e = 0; e != 10; ++e)
                        check[a][b][c][d][e] = table[table[table[table[table[0][a]][b]][c]][d]][e];
    printf("%lld\n", error());
    return 0;
}
