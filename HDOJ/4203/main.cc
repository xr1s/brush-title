#include <cstdio>
using namespace std;

int T, S, K;

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &S, &K);
        printf("%d\n", ~K & 1 && (S %= K + 1) == K ? K : S & 1);
    }
    return 0;
}
