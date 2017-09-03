#include <cstdio>
#include <cstring>
using namespace std;

int P, ds, B;
char D[10000005];

int main() {
    for (scanf("%d", &P); P; --P) {
        scanf("%d%d%s", &ds, &B, D);
        int Dlen = strlen(D), answer = 0;
        for (int i = 0; i != Dlen; ++i)
            ((answer *= B) += D[i] - '0') %= B - 1;
        printf("%d %d\n", ds, answer);
    }
    return 0;
}
