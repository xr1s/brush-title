#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

char wholeline[200];
char line[1005][100][100];
int linum, word[1005];
size_t space[100];

int main() {
    freopen("alignment.in", "r", stdin);
    freopen("alignment.out", "w", stdout);
    while (fgets(wholeline, sizeof wholeline, stdin)) {
        if (strlen(wholeline) == 1) break;
        int last = 0, linelen = strlen(wholeline);
        while (last < linelen) {
            sscanf(wholeline + last, "%s", line[linum][word[linum]]);
            while (isspace(wholeline[last])) ++last;
            last += strlen(line[linum][word[linum]++]);
        }
        for (int i = 1; i != word[linum]; ++i)
            space[i] = max(space[i], strlen(line[linum][i - 1]) + 1);
        ++linum;
    }
    for (int i = 0; i != linum; ++i) {
        for (int j = 0; j != word[i]; ++j) {
            printf("%s", line[i][j]);
            if (j < word[i] - 2) {
                for (int k = strlen(line[i][j]); k != space[j + 1]; ++k)
                    putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}
