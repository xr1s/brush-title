#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long w, h, b, img[105][105];
long long blur[105][105], color[10005];

long long average(long long i, long long j) {
    long long ave = 0;
    long long l = j - 1, r = j + 1;
    long long d = i - 1, u = i + 1;
    ((l %= w) += w) %= w;
    ((r %= w) += w) %= w;
    ((d %= h) += h) %= h;
    ((u %= h) += h) %= h;
    ave += img[d][l] + img[d][j] + img[d][r];
    ave += img[i][l] + img[i][j] + img[i][r];
    ave += img[u][l] + img[u][j] + img[u][r];
    return ave / 9;
}

int main() {
    scanf("%lld%lld%lld", &w, &h, &b);
    for (long long i = 0; i != h; ++i)
        for (long long j = 0; j != w; ++j) {
            scanf("%lld", &img[i][j]);
            img[i][j] *= 387420489ll;
        }
    while (b--) {
        for (long long i = 0; i != h; ++i)
            for (long long j = 0; j != w; ++j)
                blur[i][j] = average(i, j);
        memcpy(img, blur, sizeof img);
    }
    for (long long i = 0; i != h; ++i)
        for (long long j = 0; j != w; ++j)
            color[i * w + j] = img[i][j];
    sort(color, color + w * h);
    printf("%lu\n", unique(color, color + w * h) - color);
    return 0;
}
