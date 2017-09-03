#include <cstdio>
using namespace std;

int N, K;
int previous, current;
long long ans;

int main() {
    scanf("%d%d", &N, &K);
    scanf("%d", &previous);
    for (int i = 1; i != N; ++i) {
        scanf("%d", &current);
        if (current != previous)
            ans += 1, previous = current;
    }
    printf("%.9lf", ans * (K - 1) / (double)K);
    return 0;
}
