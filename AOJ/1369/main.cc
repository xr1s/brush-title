#include <cstdio>
#include <algorithm>
#include <bitset>
#include <utility>

using namespace std;

int n, m;
pair<int, int> arm[200005];
int accept[200005][3];  // higher, self, lower
bitset<200005> trans;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) accept[i][1] = 1;
    for (int i = 0; i != m; ++i)
        scanf("%d%d", &arm[i].first, &arm[i].second);
    sort(arm, arm + m);
    for (int i = 0; i != m; ++i) {
        int l = arm[i].second, h = l + 1;
        if (!trans.test(l)) {
            accept[l][2] = accept[h][1];
            accept[h][0] = accept[l][1];
            trans.set(l);
        }
        accept[l][2] += accept[h][2]; accept[h][1] += accept[h][2]; accept[h][2] = 0;
        accept[h][0] += accept[l][0]; accept[l][1] += accept[l][0]; accept[l][0] = 0;
    }
    for (int i = 1; i != n; ++i)
        printf("%d ", accept[i][0] + accept[i][1] + accept[i][2]);
    printf("%d\n", accept[n][0] + accept[n][1] + accept[n][2]);
    return 0;
}
