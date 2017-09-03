#include <cstdio>
#include <cmath>
#include <limits>
using namespace std;

int n, x[405];
auto minimum = numeric_limits<long double>::max();
int l, r;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) scanf("%d", &x[i]);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != i; ++j) {
            long double dist = (long double)(x[i] - x[j]) / (i - j);
            long double move = 0.l;
            for (int k = 0; k != n; ++k)
                move += abs(x[i] - i * dist - x[k] + k * dist);
            if (move < minimum) minimum = move, l = i, r = j;
        }
    printf("%.4Lf\n", minimum);
    long double dist = (long double)(x[l] - x[r]) / (l - r);
    printf("%.10Lf", x[l] - l * dist);
    for (int k = 1; k != n; ++k)
        printf(" %.10Lf", x[l] + (k - l) * dist);
    putchar('\n');
    return 0;
}
