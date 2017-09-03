#include <cstdio>
using namespace std;

long long K, N, M;

int main() {
    for (scanf("%lld", &K); K; --K) {
        scanf("%lld%lld", &N, &M);
        if (M == 1 || N == 1) {
            puts("No");
            continue;
        }
        puts(M * N % 6 == 0 ? "Yes" : "No");
    }
    return 0;
}
