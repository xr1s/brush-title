#include <cstdio>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
tuple<int, long long, int> wv[300005];
long long fun[2000005];
int day;

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        int m, f, w; scanf("%d%d%d", &m, &f, &w);
        get<0>(wv[i]) = m + w;
        get<1>(wv[i]) = f;
        get<2>(wv[i]) = m;
        day = max(day, m + w);
    }
    sort(wv, wv + n);
    int cur = 0;
    for (int i = 1; i <= day; ++i) {
        fun[i] = fun[i - 1];
        while (get<0>(wv[cur]) == i) {
            fun[i] = max(fun[i], fun[get<2>(wv[cur])] + get<1>(wv[cur]));
            ++cur;
        }
    }
    printf("%lld\n", fun[day]);
    return 0;
}
