#include <cstdio>
using namespace std;

int N, A[100005];
int kase;

int gcd(int m, int n) {
    int r = m % n;
    while ((r = m % n))
        m = n, n = r;
    return n;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        printf("Case %d: ", ++kase);
        scanf("%d", &A[0]); int g = A[0];
        for (int i = 1; i != N; ++i) {
            scanf("%d", &A[i]); g = gcd(g, A[i]);
        }
        if (g != 1) {
            puts("-1\n");
            continue;
        }
        printf("%d\n", 2 * N - 2);
        for (int i = 1; i != N; ++i)
            printf("1 %d\n", i + 1);
        for (int i = 1; i != N; ++i)
            printf("1 %d\n", i + 1);
        putchar('\n');
    }
    return 0;
}
