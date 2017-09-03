#include <cstdio>
using namespace std;

long long P, D, n;
long long answer[] = { 1ll, 1ll, 2ll, 4ll, 10ll, 32ll, 122ll, 544ll, 2770ll, 15872ll, 101042ll, 707584ll, 5405530ll, 44736512ll, 398721962ll, 3807514624ll, 38783024290ll, 419730685952ll, 4809759350882ll, 58177770225664ll, 740742376475050ll, };

int main() {
    for (scanf("%lld", &P); P; --P) {
        scanf("%lld%lld", &D, &n);
        printf("%lld %lld\n", D, answer[n]);
    }
    return 0;
}
