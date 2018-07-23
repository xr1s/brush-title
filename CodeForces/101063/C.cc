#include <cstdio>
using namespace std;

int N, M;
double K;
int Q;
long long set[1024];
long long ans;

int count_bit(int b) {
    int bit = 0;
    for (int i = 0; i != 10; ++i) {
        if (b & (1 << i)) ++bit;
    }
    return bit;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i != N; ++i) {
        scanf("%d", &Q); int s = 0;
        for (int j = 0; j != Q; ++j) {
            int q; scanf("%d", &q);
            s |= 1 << q - 1;
        }
        ++set[s];
    }
    scanf("%lf", &K);
    for (int i = 0; i != 1024; ++i)
        for (int j = 0; j != 1024; ++j)
            if (count_bit(i & j) && count_bit(i | j))
                if (count_bit(i & j) >= K * count_bit(i | j))
                    ans += set[i] * set[j];
    printf("%lld\n", ans - N >> 1);
    return 0;
}

