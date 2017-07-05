#include <stdio.h>

int main() {
    unsigned long long fib[2] = {1, 0}, sum = 0;
    for (int i = 0; i != 9; ++i)
        fib[i & 1] += fib[i & 1 ^ 1];
    for (int i = 9; i != 17; ++i) {
        sum += fib[i & 1] += fib[i & 1 ^ 1];
    }
    printf("%llu", sum);
    return 0;
}
