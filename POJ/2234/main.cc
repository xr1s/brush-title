#include <cstdio>
using namespace std;

int M, match;

int main() {
    while (~scanf("%d", &M)) {
        int sg = 0;
        while (M--) {
            scanf("%d", &match);
            sg ^= match;
        }
        puts(sg ? "Yes" : "No");
    }
    return 0;
}
