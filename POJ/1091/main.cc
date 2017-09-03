#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long N, M;
long long factor[100], fnum;

long long power(long long base, long long pow) {
    long long result = 1;
    do {
        if (pow & 1) result *= base;
        if (pow ^ 1) base *= base;
    } while (pow >>= 1);
    return result;
}

int main() {
    while (cin >> N >> M) {
        long long t = M, sq = (long long)(ceil(sqrt(M)));
        for (long long i = 2; i <= sq; ++i)
            if (t % i == 0) {
                factor[fnum++] = i;
                do t /= i; while (t % i == 0);
            }
        if (t != 1) factor[fnum++] = t;
        sort(factor, factor + fnum);
        fnum = unique(factor, factor + fnum) - factor;
        long long answer = 0;
        for (long long i = 0; i != 1 << fnum; ++i) {
            long long select = 1, pn = 1;
            for (long long j = 0; j != fnum; ++j)
                if (i & 1 << j) select *= factor[j], pn *= -1;
            answer += pn * power(M / select, N);
        }
        cout << answer << endl;
    }
    return 0;
}
