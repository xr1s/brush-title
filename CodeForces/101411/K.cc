#include <cstdio>
#include <cmath>

using namespace std;

long double N, M;

int main() {
#ifndef LOCAL
    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w", stdout);
#endif
    scanf("%Lf%Lf", &N, &M);
    printf("%.9Lf\n", N - N * powl((N - 1) / N, M));
    return 0;
}
