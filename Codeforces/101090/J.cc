#include <cstdio>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    long long e = N >> 1, o = N + 1 >> 1;
    printf("%lld\n", e * (e - 1) * (e - 2) / 6 + e * o * (o - 1) / 2);
    return 0;
}
