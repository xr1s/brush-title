#include <stdio.h>
int main() {
    long long n = 1000000000;
    long long sum = 0;
    for (int i = 3; i < n; i += 3) sum += i;
    for (int i = 5; i < n; i += 5) sum += i;
    for (int i = 15; i < n; i += 15) sum -= i;
    printf("%lld\n", sum);
    return 0;
}
