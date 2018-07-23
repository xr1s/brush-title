#include <cstdio>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
tuple<long long, long long, long long, long long> c[5005];
bool fake[5005];
long long answer;

#define x1(i) get<0>(c[i])
#define x2(i) get<2>(c[i])
#define y1(i) get<1>(c[i])
#define y2(i) get<3>(c[i])
constexpr tuple<long long, long long, long long, long long> invalid = make_tuple(0, 0, 0, 0);

bool connect(int i, int j) {
    return x1(i) == x1(j) && y1(i) == y1(j)
        || x1(i) == x2(j) && y1(i) == y2(j)
        || x2(i) == x1(j) && y2(i) == y1(j)
        || x2(i) == x2(j) && y2(i) == y2(j);
}

int main() {
#ifndef LOCAL
    freopen("lshape.in", "r", stdin);
    freopen("lshape.out", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%lld%lld%lld%lld", &x1(i), &y1(i), &x2(i), &y2(i));
    for (int i = 0; i != N; ++i) {
        if (c[i] == invalid) continue;
        for (int j = i + 1; j != N; ++j) {
            if (c[j] == invalid) continue;
            if (fake[j]) continue;
            if (connect(i, j) && (x1(i) - x2(i)) * (x1(j) - x2(j)) +
                                 (y1(i) - y2(i)) * (y1(j) - y2(j)) == 0) {
                ++answer;
            }
        }
    }
    printf("%lld\n", answer);
    return 0;
}
