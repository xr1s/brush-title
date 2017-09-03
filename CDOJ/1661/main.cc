#include <cstdio>

using namespace std;

long long T, N, a;

long long sg(long long a) {
    while (a & 1) a >>= 1;
    return a >> 1;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        long long win = 0;
        for (scanf("%d", &N); N; --N) {
            scanf("%lld", &a);
            win ^= sg(a);
        }
        puts(win ? "YES" : "NO");
    }
    return 0;
}
