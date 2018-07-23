#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, a[1000005];
int hill[1000005][2];
int dale[1000005][2];

int main() {
#ifndef LOCAL
    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);
#endif
    for (scanf("%d", &T); T; --T) {
        int hillans = 0, daleans = 0;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
        // Hills
        a[0] = a[N + 1] = ~0u >> 1;
        for (int i = 1; i <= N; ++i) hill[i][0] = hill[i][1] = i;
        for (int i = 1; i <= N; ++i)
            if (a[i] > a[i - 1]) hill[i][0] = hill[i - 1][0];
        for (int i = N; i >= 1; --i)
            if (a[i] > a[i + 1]) hill[i][1] = hill[i + 1][1];
        for (int i = 1; i <= N; ++i)
            hillans = max(hillans, min(i - hill[i][0], hill[i][1] - i));
        // Dales
        a[0] = a[N + 1] = 1 << 31;
        for (int i = 1; i <= N; ++i) dale[i][0] = dale[i][1] = i;
        for (int i = 1; i <= N; ++i)
            if (a[i] < a[i - 1]) dale[i][0] = dale[i - 1][0];
        for (int i = N; i >= 1; --i)
            if (a[i] < a[i + 1]) dale[i][1] = dale[i + 1][1];
        for (int i = 1; i <= N; ++i)
            daleans = max(daleans, min(i - dale[i][0], dale[i][1] - i));
        printf("%d %d\n", hillans, daleans);
    }
    return 0;
}
