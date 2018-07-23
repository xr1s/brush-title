#include <cstdio>
#include <cstring>
using namespace std;

int K;
char board[100005];
int len;

bool judge(int bef, int aft) {
    return ~bef && ~aft && aft > bef && (aft - bef - 1) % K == 0;
}

int main() {
    scanf("%d%s", &K, board);
    len = strlen(board);
    for (int i = 0; i != K; ++i) {
        int bef0 = -1, bef1 = -1, aft0 = -1, aft1 = -1;
        for (int j = i; j < len; j += K)
            if (board[j] == '1')
                if (!~bef0) bef0 = j; else bef1 = j;
        for (int j = i + 1; j < len; j += K)
            if (board[j] == '1')
                if (!~aft0) aft0 = j; else aft1 = j;
        if (judge(bef0, aft0)) {
            printf("%d %d\n", bef0 + 1, aft0 + 1);
            return 0;
        }
        if (judge(bef0, aft1)) {
            printf("%d %d\n", bef0 + 1, aft1 + 1);
            return 0;
        }
        if (judge(bef1, aft0)) {
            printf("%d %d\n", bef1 + 1, aft0 + 1);
            return 0;
        }
        if (judge(bef1, aft1)) {
            printf("%d %d\n", bef1 + 1, aft1 + 1);
            return 0;
        }
    }
    puts("0 0");
    return 0;
}
