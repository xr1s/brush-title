#include <cstdio>
#include <list>
#include <bitset>
#include <algorithm>

using namespace std;

int prufer[7505], len, node;
bitset<7505> xst;
bitset<7505> ing;
list<int> adj[7505];
int set[7505];

int main() {
    while (~scanf("%d", &prufer[len++]) && prufer[len - 1]); --len;
    node = len + 1;
    for (int i = 0; i != len; ++i) {
        xst = ing;
        for (int j = i; j != len; ++j) xst.set(prufer[j]);
        int u = 1, v = prufer[i];
        while (xst[u]) ++u;
        ing.set(u);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= node; ++i) {
        printf("%d:", i);
        int n = 0;
        for (auto &it: adj[i])
            set[n++] = it;
        sort(set, set + n);
        for (int i = 0; i != n; ++i)
            printf(" %d", set[i]);
        putchar('\n');
    }
    return 0;
}
