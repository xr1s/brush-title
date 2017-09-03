#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

int N, K;
pair<int, int> blk[100005];

int dist(pair<int, int> &b0, pair<int, int> &b1) {
    return b0.second - b1.second - 1;
}

int main(){
    while (scanf("%d%d", &N, &K) != EOF) {
        for (int i = 0; i != N; ++i) {
            int color; scanf("%d", &color);
            blk[i] = make_pair(color, i);
        }
        sort(blk, blk + N);
        int remv = 0, maxi = 1, l = 0, r = 1;
        for (; r <= N; ++r) {
            if (blk[r].first == blk[r - 1].first) {
                remv += dist(blk[r], blk[r - 1]);
                while (remv > K)
                    ++l, remv -= dist(blk[l], blk[l - 1]);
                maxi = max(maxi, dist(blk[r], blk[l]) + 2 - remv);
            } else {
                maxi = max(maxi, dist(blk[r - 1], blk[l]) + 2 - remv);
                l = r, remv = 0;
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
