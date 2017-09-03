#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
    int x0, y0, z0, x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d%d%d%d%d%d%d", &x0, &y0, &z0, &x1, &y1, &z1, &x2, &y2, &z2);
    long long xdis = min(abs(x0 - x2), abs(x0 - x1)); xdis *= xdis;
    long long ydis = min(abs(y0 - y1), abs(y0 - y2)); ydis *= ydis;
    long long zdis = min(abs(z0 - z1), abs(z0 - z2)); zdis *= zdis;
    if (x1 <= x0 && x0 <= x2 && y1 <= y0 && y0 <= y2 && z1 <= z0 && z0 <= z2) {
        puts("0");
        return 0;
    }
    if (y1 <= y0 && y0 <= y2 && z1 <= z0 && z0 <= z2) {
        printf("%lld\n", xdis);
        return 0;
    }
    if (x1 <= x0 && x0 <= x2 && z1 <= z0 && z0 <= z2) {
        printf("%lld\n", ydis);
        return 0;
    }
    if (x1 <= x0 && x0 <= x2 && y1 <= y0 && y0 <= y2) {
        printf("%lld\n", zdis);
        return 0;
    }
    if (x1 <= x0 && x0 <= x2) {
        printf("%lld\n", ydis + zdis);
        return 0;
    }
    if (y1 <= y0 && y0 <= y2) {
        printf("%lld\n", xdis + zdis);
        return 0;
    }
    if (z1 <= z0 && z0 <= z2) {
        printf("%lld\n", xdis + ydis);
        return 0;
    }
    printf("%lld\n", xdis + ydis + zdis);
    return 0;
}
