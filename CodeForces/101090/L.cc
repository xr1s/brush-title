#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int S, l[1005];
char c[1005];
int seg[2][1005], segnum[2], num;

int main() {
    while (~scanf("%d", &S)) {
        segnum[0] = segnum[1] = 0;
        for (int i = 0; i != S; ++i) {
            char stat[5]; scanf("%s", stat);
            int length, color;
            sscanf(stat, "%d%[BR]", &length, &color);
            color = color == 'B';
            seg[color][segnum[color]++] = length;
        }
        sort(seg[0], seg[0] + segnum[0], greater<int>());
        sort(seg[1], seg[1] + segnum[1], greater<int>());
        num = min(segnum[0], segnum[1]);
        long long length = 0;
        for (int i = 0; i != num; ++i)
            length += seg[0][i] + seg[1][i];
        printf("%lld\n", length - num * 2);
    }
    return 0;
}
