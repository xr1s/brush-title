#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, A[105];
int maxi;

int dist(int l, int r) {
    int diff = 0;
    for (int i = 30; ~i; --i)
        diff += !!(l & 1 << i ^ r & 1 << i);
    return diff;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        maxi = 0;
        scanf("%d", &N);
        for (int i = 0; i != N; ++i) scanf("%d", &A[i]);
        for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                maxi = max(maxi, dist(A[i], A[j]));
        printf("%d\n", maxi);
    }
    return 0;
}
