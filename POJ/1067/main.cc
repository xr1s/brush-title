#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const long double phi = sqrt(5.l) / 2.l + .5l;
int a, b;

int main() {
    while (~scanf("%d%d", &a, &b)) {
        if (a > b) swap(a, b);
        putchar(((int)((b - a) * phi) != a) + '0');
        putchar('\n');
    }
    return 0;
}
