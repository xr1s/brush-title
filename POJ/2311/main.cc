#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int W, H;
int nim[205][205];

int sg(int W, int H) {
    if (~nim[W][H]) return nim[W][H];
    set<int> xst;
    for (int i = 2; i + 1 < W; ++i)
        xst.insert(sg(i, H) ^ sg(W - i, H));
    for (int i = 2; i + 1 < H; ++i)
        xst.insert(sg(W, i) ^ sg(W, H - i));
    for (int i = 0; ; ++i)
        if (xst.find(i) == xst.end())
            return nim[W][H] = i;
}

int main() {
    memset(nim, -1, sizeof nim);
    while (~scanf("%d%d", &W, &H))
        puts(sg(W, H) ? "WIN" : "LOSE");
    return 0;
}
