#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long P, ds, n;

long long dfs(long long n) {
    long long answer = n;
    while (n != 1) {
        switch (n & 1) {
            case 0: answer = max(answer, n >>= 1); break;
            case 1: answer = max(answer, (n *= 3) += 1); break;
        }
    }
    return answer;
}

int main() {
    for (scanf("%lld", &P); P; --P) {
        scanf("%lld%lld", &ds, &n);
        printf("%lld %lld\n", ds, dfs(n));
    }
    return 0;
}
