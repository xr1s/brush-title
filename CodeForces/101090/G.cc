#include <cstdio>
using namespace std;

int N, K;
int bkt[600005];
int indx[600005][2];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i != K; ++i) {
        int number; scanf("%d", &number);
        ++bkt[number];
        if (indx[number][0] != 0) {
            indx[number][1] = i + 1;
        } else indx[number][0] = i + 1;
    }
    for (int i = 1; i <= N; ++i)
        if (bkt[i] > 1) {
            printf("%d %d\n", indx[i][0], indx[i][1]);
            return 0;
        } else if (bkt[i]) {
            for (int j = i << 1; j <= N; j += i)
                if (bkt[j]) {
                    printf("%d %d\n", indx[j][0], indx[i][0]);
                    return 0;
                }
        }
    puts("0 0");
    return 0;
}
