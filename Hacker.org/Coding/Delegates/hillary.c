#include <stdio.h>
int main() {
    long long barack = 2118;
    long long hillary = 0;
    for (int i = 0; i <= 2118; ++i) hillary += i;
    for (int i = 0; i * i <= 2118; ++i) hillary += i * i;
    printf("%ld\n", hillary);
    return 0;
}
