#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

int T, Q, M, q[105][105], a[105][105];
int answer[105][4];

bool isselect(char sel) {
    return 'A' <= sel && sel <= 'D';
}


int main() {
    for (scanf("%d", &T); T; --T) {
        memset(answer, -1, sizeof answer);
        scanf("%d%d", &Q, &M);
        for (int i = 0; i != M; ++i)
            for (int j = 0; j != Q; ++j) {
                char select, result;
                while (!isselect(select = getchar()));
                while ((result = getchar()) != 'T' && result != 'F');
                switch (result) {
                    case 'T':
                        if (answer[j][select - 'A'] != -2) {
                            memset(answer[j], 0, sizeof *answer);
                            answer[j][select - 'A'] = 1;
                        }
                        break;
                    case 'F':
                        if (answer[j][select - 'A'] == 1)
                            for (int k = 0; k != 4; ++k) answer[j][k] = -2;
                        else answer[j][select - 'A'] = 0;
                        break;
                }
            }
        for (int i = 0; i != Q; ++i) {
            int wrong = 0;
            for (int j = 0; j != 4; ++j)
                wrong += answer[i][j] == 0;
            if (wrong == 3) {
                for (int j = 0; j != 4; ++j)
                    if (answer[i][j] != 0) putchar('A' + j);
            } else putchar('?');
            putchar(i + 1 == Q ? '\n' : ' ');
        }
    }
    return 0;
}
