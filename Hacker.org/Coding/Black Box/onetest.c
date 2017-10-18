#include <stdio.h>
#include <stdlib.h>

int main() {
    register int32_t eax;
    for (register int32_t eax = 0; eax != 2147483647; ++eax)
        if (22233442 * (eax - 7333333 ^ 0x2eb22189) == 186968300)
            printf("%d\n", eax);
    return 0;
}
