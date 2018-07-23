#include <cstdio>
#include <cstring>

using namespace std;

char str[105];
int diff, cnt[128];
int max1 = 0, max2 = 0;
int answer;

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i != len; ++i)
        ++cnt[str[i]];
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] >= cnt[max1]) {
            max2 = max1; max1 = i;
        } else if (cnt[i] > cnt[max2]) {
            max2 = i;
        }
    }
    for (int i = 'a'; i <= 'z'; ++i)
        if (i != max1 && i != max2) answer += cnt[i];
    printf("%d\n", answer);
    return 0;
}
