#include <stdio.h>

int n, k[1000];

int main() {
    while (~scanf("%d", &n) && n) {
        int sg = 0, count = 0;
        for (int i = 0; i != n; ++i) {
            scanf("%d", &k[i]);
            sg ^= k[i];
        }
        for (int i = 0; i != n; ++i)
            count += sg ^ k[i] < k[i];
        printf("%d\n", count);
    }
    return 0;
}
