#include <stdio.h>
#include <math.h>

int len[100];

int power(int base, int exponent) {
    int result = 1;
    do {
        if (exponent & 1) result *= base;
        if (exponent ^ 1) base *= base;
    } while (exponent >>= 1);
    return result;
}

int calc(int num) {
    int result = 0;
    for (int i = 0; i != num; ++i)
        result += len[i] * power(num, 4) * 5;
    return result + 16 * power(num, 5);
}

int main() {
    for (int i = 0; i != 100; ++i)
        len[i] = (int)(ceil(log10(i + 1)));
    len[0] = 1;
    for (int i = 0; i != 100; ++i) {
        printf("%d\n", 99 - i);
        printf("val: %d\n", calc(i));
    }
    return 0;
}
