#include <cmath>
#include <cstdio>
using namespace std;

int N, M, x, l, r;
long long data[400005];
bool lazy[400005];

void push_up(int RT) {
    data[RT] = data[RT << 1] + data[RT << 1 | 1];
    lazy[RT] = lazy[RT << 1] & lazy[RT << 1 | 1];
}

void build(int RT, int L, int R) {
    if (L + 1 == R) {
        scanf("%lld", &data[RT]);
        if (data[RT] <= 1)
            lazy[RT] = true;
        return;
    }
    int M = L + R >> 1;
    build(RT << 1 | 0, L, M);
    build(RT << 1 | 1, M, R);
    push_up(RT);
}

void update(int l, int r, int RT, int L, int R) {
    if (lazy[RT]) return;
    if (L + 1 == R) {
        data[RT] = sqrt(data[RT]);
        if (data[RT] <= 1)
            lazy[RT] = true;
        return;
    }
    long long M = L + R >> 1;
    if (l < M) update(l, r, RT << 1 | 0, L, M);
    if (r > M) update(l, r, RT << 1 | 1, M, R);
    push_up(RT);
}

long long query(int l, int r, int RT, int L, int R) {
    if (l <= L && R <= r) return data[RT];
    int M = L + R >> 1;
    long long sum = 0;
    if (l < M) sum += query(l, r, RT << 1 | 0, L, M);
    if (r > M) sum += query(l, r, RT << 1 | 1, M, R);
    return sum;
}

int main() {
    scanf("%d", &N);
    build(1, 0, N);
    for (scanf("%d", &M); M; --M) {
        scanf("%d%d%d", &x, &l, &r);
        switch (x) {
            case 1:
                printf("%lld\n", query(l - 1, r, 1, 0, N));
                break;
            case 2:
                update(l - 1, r, 1, 0, N);
                break;
        }
    }
    return 0;
}
