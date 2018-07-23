#include <cstdio>
using namespace std;

int T, N, a[1005];

int main() {
    for (scanf("%d", &T); T; --T) {
        int win = 0;
        scanf("%d", &N);
        for (int i = 0; i != N; ++i) scanf("%d", &a[i]);
        for (int i = 0; i != N; ++i) {
            int left = a[i] % (N * (N - 1));
            win += 0 < left && left < N;
        }
        puts(win == N ? "Bob" : "Alice");
    }
    return 0;
}
