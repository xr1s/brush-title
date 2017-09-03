#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, pre[10005];
int child[10005][2], chnum[10005];
int space[10005];

void dfs(int s) {
    if (chnum[s] == 0) {
        space[s] = 1;
        return;
    }
    for (int i = 0; i != chnum[s]; ++i)
        dfs(child[s][i]);
    space[s] = min(
            max(space[child[s][0]] + 1, space[child[s][1]]),
            max(space[child[s][0]], space[child[s][1]] + 1));
}

int main() {
    while (~scanf("%d", &n) && n) {
        memset(pre, 0, sizeof pre);
        memset(child, 0, sizeof child);
        memset(chnum, 0, sizeof chnum);
        memset(space, 0, sizeof space);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &pre[i]);
            child[pre[i]][chnum[pre[i]]++] = i;
        }
        dfs(1);
        printf("%d\n", space[1]);
    }
    return 0;
}
