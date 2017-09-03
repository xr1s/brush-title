#include <algorithm>
#include <cstdio>
using namespace std;

long long n;
long long p[60] = {1};

int main() {
    scanf("%lld", &n);
    for (int i = 1; i != 60; ++i) p[i] = p[i - 1] << 1;
    long long loc = lower_bound(p, p + 60, n) - p;
    printf("%lld\n", loc + 1);
    return 0;
}
