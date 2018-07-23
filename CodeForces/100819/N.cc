#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int n, k;
int s[2][105], sn[2];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i != n; ++i) {
        int floor; char status[10];
        scanf("%d%s", &floor, status);
        if (!strcmp(status, "SAFE"))    s[0][sn[0]++] = floor;
        if (!strcmp(status, "BROKEN"))  s[1][sn[1]++] = floor;
    }
    s[0][sn[0]++] = 1; s[1][sn[1]++] = k;
    sort(s[0], s[0] + sn[0], greater<int>());
    sort(s[1], s[1] + sn[1], less<int>());
    printf("%d %d\n", s[0][0] + 1, s[1][0] - 1);
    return 0;
}
