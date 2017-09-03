#include <cstdio>
using namespace std;

long long N, is[30];

int main() {
    for (scanf("%lld", &N); N; --N) {
        for (int i = 0; i != 20; ++i) scanf("%lld", &is[i]);
        for (int i = 19; i; --i)
            is[i - 1] += is[i] >> 1, is[i] &= 1;
        for (int i = 0; i != 19; ++i)
            printf("%lld ", is[i]);
        printf("%lld\n", is[19]);
    }
    return 0;
}
