#include <cstdio>
#include <algorithm>
#include <bitset>
#include <utility>

using namespace std;

constexpr long long over = 1000000000;

int n;
bitset<over + 5> place;
long long curmax;

int main() {
    place.set(0);
    for (scanf("%d", &n); n; --n) {
        long long x; scanf("%lld", &x);
        if (x == curmax) {
            puts("Yes");
            place.reset(curmax);
            while (!place.test(curmax) && curmax != over)
                ++curmax;
            continue;
        }
        if (x < curmax) {
            puts("No");
            continue;
        }
        if (place.test(x)) {
            place.reset(x);
            puts("Yes");
            continue;
        }
        while (!place.test(x))
            place.set(x--);
        place.reset(x);
        if (x == curmax) ++curmax;
        puts("Yes");
    }
    return 0;
}
