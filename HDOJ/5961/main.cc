#include <cctype>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int T, n;
bitset<2020> g[2][2020];

template <size_t sz>
bool transitive(const bitset<sz> (&g)[sz]) {
    bool transitive = true;
    for (int i = 0; transitive && i != n; ++i)
        for (int j = 0; transitive && j != n; ++j)
            transitive &= !g[i][j] || (g[i] & g[j]) == g[j];
    return transitive;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &n);
        for (int i = 0; i != n; ++i)
            g[0][i].reset(), g[1][i].reset();
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j) {
                char adj; while (isspace(adj = getchar()));
                if (adj != '-') g[adj == 'Q'][i][j] = true;
            }
        puts(transitive(g[0]) && transitive(g[1]) ? "T" : "N");
    }
    return 0;
}#include <cctype>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int T, n;
bitset<2020> g[2][2020];

template <size_t sz>
bool transitive(const bitset<sz> (&g)[sz]) {
    bool transitive = true;
    for (int i = 0; transitive && i != n; ++i)
        for (int j = 0; transitive && j != n; ++j)
            transitive &= !g[i][j] || (g[i] & g[j]) == g[j];
    return transitive;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &n);
        for (int i = 0; i != n; ++i)
            g[0][i].reset(), g[1][i].reset();
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j) {
                char adj; while (isspace(adj = getchar()));
                if (adj != '-') g[adj == 'Q'][i][j] = true;
            }
        puts(transitive(g[0]) && transitive(g[1]) ? "T" : "N");
    }
    return 0;
}
