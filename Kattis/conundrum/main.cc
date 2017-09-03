#include <cstdio>
#include <cstring>

using namespace std;

char s[305];
int len, ans;

int main() {
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < len; i += 3)
        ans += (s[i] != 'P') + (s[i + 1] != 'E') + (s[i + 2] != 'R');
    printf("%d\n", ans);
    return 0;
}
