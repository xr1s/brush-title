#include <cstdio>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

int P, ds, N;
long long f[10000], s[10000];
long long answer;

int main() {
    f[0] = 1, f[1] = -1, f[2] = 1, f[3] = 3;
    for (int i = 4; i != 10000; ++i) f[i] = f[i - 3] + 4;
    for (int i = 1; i != 10000; ++i) f[i] += f[i - 1];
    s[0] = 0, s[1] = 1, s[2] = 1, s[3] = 3, s[4] = 5;
    for (int i = 5; i != 10000; ++i) s[i] = s[i - 3] + 4;
    for (int i = 1; i != 10000; ++i) s[i] += s[i - 1];
    for (scanf("%d", &P); P; --P) {
        scanf("%d%d", &ds, &N);
        int j = N >> 2;
        switch (N & 3) {
            case 0: answer = f[N >> 2]; break;
            case 1: answer = f[N + 3 >> 2]; break;
            case 2: answer = s[N >> 2]; break;
            case 3: answer = s[N + 1 >> 2]; break;
        }
        printf("%d %lld\n", ds, answer);
    }
}
