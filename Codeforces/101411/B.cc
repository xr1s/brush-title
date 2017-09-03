#include <cstdio>
using namespace std;

char a[5], b[5];
int bull, cow;

int main() {
    freopen("bulls.in", "r", stdin);
    freopen("bulls.out", "w", stdout);
    scanf("%s%s", a, b);
    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 4; ++j)
            if (i != j && a[i] == b[j]) ++cow;
    for (int i = 0; i != 4; ++i)
        if (a[i] == b[i]) ++bull;
    printf("%d %d\n", bull, cow);
    return 0;
}
