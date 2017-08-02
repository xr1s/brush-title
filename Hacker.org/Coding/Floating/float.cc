#include <stdio.h>
int main() {
    union {
        float f;
        int i = 0b1000001000010001010001011000000;
    } fi;
    printf("%lf\n", fi.f);
    return 0;
}
