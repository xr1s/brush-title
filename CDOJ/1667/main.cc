#include <cstdio>
#include <algorithm>

using namespace std;

long long T, N, a[105];
long long pre[105], maxw[105];

int main() {
    for (scanf("%d", &T); T; --T) {
        long long sum = 0, maxi = 0;
        scanf("%d", &N);
        for (int i = 0; i != N; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for (int i = 0; i != N; ++i) {
            maxw[i] = 0;
            for (int j = 0; j != i; ++j)
                if (a[j] <= a[i] && maxw[j] > maxw[i])
                    maxw[i] = maxw[j];
            maxw[i] += a[i];
            maxi = max(maxi, maxw[i]);
        }
        printf("%lld\n", sum - maxi);
    }
    return 0;
}
