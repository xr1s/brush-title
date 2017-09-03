#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long m, n, t;
long long p[60], l;
bool ac;

int main() {
    cin >> m >> n >> t;
    switch (t) {
        case 1:
            if (n <= 15ll) {
                long long factorial = 1;
                for (long long i = 2; i <= n; ++i) factorial *= i;
                ac = factorial <= m;
            } else ac = false;
            break;
        case 2:
            if (n <= 60ll) {
                ac = 1ll << n <= m;
            } else ac = false;
            break;
        case 3:
            if (n <= 40000ll) {
                ac = n * n * n * n <= m;
            } else ac = false;
            break;
        case 4:
            if (n <= 1000000ll) {
                ac = n * n * n <= m;
            } else ac = false;
            break;
        case 5:
            if (n <= 2000000000ll) {
              ac = n * n <= m;
            } else ac = false;
            break;
        case 6:
            if (n >= m) {
                ac = false;
                break;
            }
            p[0] = 1;
            for (long long i = 1; i != 60; ++i) p[i] = p[i - 1] << 1;
            l = lower_bound(p, p + 60, n) - p;
            if (1ll << l == n) ac = n * l <= m;
            else ac = n * log2l((long double)n) <= m;
            break;
        case 7:
            ac = n <= m;
            break;
    }
    cout << (ac ? "AC" : "TLE") << '\n';
    return 0;
}
