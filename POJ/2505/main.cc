#include <stdio.h>

const int div[] = { 9, 2 };
unsigned int n;
bool win;

int main() {
    while (~scanf("%u", &n)) {
        for (win = 0; n > 1; win ^= 1)
            (n += div[win] - 1) /= div[win];
        printf(win ? "Stan" : "Ollie");
        puts(" wins.");
    }
    return 0;
}
