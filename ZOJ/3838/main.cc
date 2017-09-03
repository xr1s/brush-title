#include <cctype>
#include <cstdio>
using namespace std;

int T, n;
char map[105][105];

bool is_map(char c) {
    return isalpha(c) || c == '.' || c == '#';
}

int change(int count[]) {
    int maxc = 'a';
    for (char c = 'a'; c <= 'z'; ++c)
        if (count[c] > count[maxc]) maxc = c;
    if (count['#'] > count[maxc]) maxc = '#';
    if (count['.'] > count[maxc]) maxc = '.';
    int diff = -count[maxc];
    for (char c = 'a'; c <= 'z'; ++c)
        diff += count[c];
    diff += count['#']; diff += count['.'];
    return diff;
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &n);
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j)
                while (!is_map(map[i][j] = getchar()));
        int answer = 0;
        for (int i = 0; i != (n >> 1) - 1; ++i)
            for (int j = i + 1; j != n >> 1; ++j) {
                int count[128] = {0};
                count[map[i][j]]++;
                count[map[j][i]]++;
                count[map[n - 1 - i][j]]++;
                count[map[j][n - 1 - i]]++;
                count[map[i][n - 1 - j]]++;
                count[map[n - 1 - j][i]]++;
                count[map[n - 1 - i][n - 1 - j]]++;
                count[map[n - 1 - j][n - 1 - i]]++;
                answer += change(count);
            }
        for (int i = 0; i != n >> 1; ++i) {
            int count[128] = {0};
            count[map[i][i]]++;
            count[map[i][n - 1 - i]]++;
            count[map[n - 1 - i][i]]++;
            count[map[n - 1 - i][n - 1 - i]]++;
            answer += change(count);
        };
        for (int i = 0; i != n >> 1; ++i) {
            int count[128] = {0};
            count[map[i][n >> 1]]++;
            count[map[n - 1 - i][n >> 1]]++;
            count[map[n >> 1][i]]++;
            count[map[n >> 1][n - 1 - i]]++;
            answer += change(count);
        };
        printf("%d\n", answer);
    }
    return 0;
}
