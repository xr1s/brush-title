#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int ti[200005];
int maxt, w, maxw;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i != n; ++i) {
        int t; scanf("%d", &t);
        ++ti[t]; --ti[t + 1000];
        maxt = max(maxt, t);
    }
    for (int i = 0; i != maxt + 1005; ++i)
        w += ti[i], maxw = max(maxw, w);
    printf("%d\n", (maxw + k - 1) / k);
    return 0;
}
