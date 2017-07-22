#include <stdio.h>
int main() {
    long long number; scanf("%lld", &number);
    while (number != 42) {
        printf("%lld\n", number);
        scanf("%lld", &number);
    }
    return 0;
}
