#include <cstdio>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
tuple<long long, long long, int> dock[1005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i != N; ++i) {
        long long x, y; scanf("%lld%lld", &x, &y);
        dock[i] = make_tuple(x, y, i + 1);
    }
    sort(dock, dock + N);
    long long dy = get<1>(dock[1]) - get<1>(dock[0]);
    long long dx = get<0>(dock[1]) - get<0>(dock[0]);
    for (int i = 2; i != N; ++i) {
        long long ny = get<1>(dock[i]) - get<1>(dock[0]);
        long long nx = get<0>(dock[i]) - get<0>(dock[0]);
        if (dy * nx != ny * dx) {
            for (int j = 1; j != N; ++j)
                printf("%d %d\n", get<2>(dock[j - 1]), get<2>(dock[j]));
            printf("%d %d\n", get<2>(dock[i]), get<2>(dock[0]));
            return 0;
        }
    }
    puts("-1");
    return 0;
}
