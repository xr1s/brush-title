#include <cstdio>
#include <cstring>
using namespace std;

int N;
char face[1024][1025];
int log[1025];

void rectagle(int x, int y, int xlen, int ylen) {
    for (int i = 0; i != xlen; ++i) {
        face[x + i][y] = '*';
        face[x + i][y + ylen - 1] = '*';
    }
    for (int i = 0; i != ylen; ++i) {
        face[x][y + i] = '*';
        face[x + xlen - 1][y + i] = '*';
    }
}

void print_face() {
    for (int i = 0; i != N; ++i) puts(face[i]);
}

void draw(int len, int x, int y, bool rev) {
    rectagle(x, y, len, len);
    if (len < 8) return;
    int interval = len >> 3;
    int eyelen = len >> 2;
    if (!rev) {
        rectagle(x + interval, y + interval, eyelen + 1, eyelen);
        rectagle(x + interval, y + len - interval - eyelen, eyelen + 1, eyelen);
        draw(len >> 1, x + (len >> 1), y + (len >> 2), !rev);
    } else {
        rectagle(x + len - interval - eyelen - 1, y + interval, eyelen + 1, eyelen);
        rectagle(x + len - interval - eyelen - 1, y + len - interval - eyelen, eyelen + 1, eyelen);
        draw(len >> 1, x, y + (len >> 2), !rev);
    }
}

int main() {
    for (int i = 8, l = 3; i <= 1024; i <<= 1, ++l) log[i] = l;
    while (scanf("%d", &N) != EOF && N >= 8) {
        memset(face, ' ', sizeof face);
        for (int i = 0; i != N; ++i) face[i][N] = '\0';
        draw(N, 0, 0, false);
        print_face();
        putchar('\n');
    }
    return 0;
}
