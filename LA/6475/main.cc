#include <cstdio>
using namespace std;

int n, im, iy, sm, sy;

int main() {
    for (scanf("%d", &n); n; --n) {
        scanf("%d%d%d%d", &im, &iy, &sm, &sy);
        if (iy != sy) printf("%.4Lf\n", sy - iy - .5l + (sm - 1) / 12.l);
        else printf("%.4Lf\n", (long double)(sm - im) / (26.l - (im * 2)));
    }
    return 0;
}
