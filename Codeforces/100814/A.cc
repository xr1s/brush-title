#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T, n[15], len;
int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, };
double invf[15];
bool occur[15];

int main() {
    for (int i = 0; i != 11; ++i) invf[i] = 1. / fact[i];
    for (scanf("%d", &T); T; --T) {
        while (!isdigit(n[len = 0] = getchar())); n[0] -= '0';
        while (isdigit(n[++len] = getchar())) n[len] -= '0';
        for (int i = 0; i != len; ++i) occur[n[i]] = true;
        int id = 1;
        for (int i = 0; i != len; occur[n[i++]] = false) {
            int count = 0;
            for (int j = 0; j != n[i]; ++j) count += occur[j];
            id += fact[len - i - 1] * count;
        }
        if (id != fact[len])
            printf("%.9lf\n", invf[len] * pow(1. + invf[len], fact[len] - id - 1));
        else puts("0.000000000");
    }
    return 0;
}
