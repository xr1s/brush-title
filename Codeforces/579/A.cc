#include <cstdio>
using namespace std;

unsigned long long x;
int count;

int main() {
    scanf("%llu", &x);
    for (int i = 0; i != 63; ++i)
        if (x & 1ull << i) ++count;
    printf("%d\n", count);
    return 0;
}
