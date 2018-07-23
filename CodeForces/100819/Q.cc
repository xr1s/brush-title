#include <cstdio>
#include <algorithm>
using namespace std;

int n, s[100005];
int mini = ~0u >> 1;

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%d", &s[i]);
    sort(s, s + n);
    for (int i = 0; i != n >> 1; ++i)
        mini = min(mini, s[i] + s[n - 1 - i]);
    printf("%d\n", mini);
    return 0;
}
