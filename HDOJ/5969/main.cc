#include <cstdio>
#include <algorithm>
using namespace std;

int T;
unsigned long long l, r;
bool bl[64], br[64];
long long log_l, log_r;

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%llu%llu", &l, &r);
        if (l == r) {
            printf("%llu\n", r);
            continue;
        }
        for (long long i = 0; i != 64; ++i) {
            bl[i] = !!(l & 1ull << i);
            br[i] = !!(r & 1ull << i);
        }
        for (log_l = 63; ~log_l; --log_l) if (bl[log_l]) break;
        for (log_r = 63; ~log_r; --log_r) if (br[log_r]) break;
        long long diff;
        for (diff = log_r; ~diff; --diff)
            if (bl[diff] != br[diff]) break;
        long long answer = 0;
        for (long long i = log_r; i != diff; --i)
            answer |= (long long)(br[i]) << i;
        answer |= (2ull << diff) - 1;
        printf("%llu\n", answer);
    }
    return 0;
}
