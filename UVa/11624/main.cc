#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

constexpr int dx[] = { 1, 0, -1, 0 };
constexpr int dy[] = { 0, 1, 0, -1 };
int T, R, C;
int sx, sy;
char map[1005][1005];
int fire[1005][1005], dis[1005][1005];
int qu[1000005], qh, qt;

inline int id(int r, int c) {
    return r * C + c;
}

void bfs() {
    for (qh = 0; qh != qt; ++qh) {
        int x = qu[qh] / C, y = qu[qh] % C;
        for (int i = 0; i != 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R) continue;
            if (ny < 0 || ny >= C) continue;
            if (map[nx][ny] == '#') continue;
            if (fire[nx][ny] > fire[x][y] + 1) {
                fire[nx][ny] = fire[x][y] + 1;
                qu[qt++] = id(nx, ny);
            }
        }
    }
}

int escape(int r, int c) {
    dis[r][c] = 0;
    for (qu[qh = qt = 0] = id(r, c); qh <= qt; ++qh) {
        int x = qu[qh] / C, y = qu[qh] % C;
        for (int i = 0; i != 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R) return dis[x][y] + 1;
            if (ny < 0 || ny >= C) return dis[x][y] + 1;
            if (map[nx][ny] == '#') continue;
            if (fire[nx][ny] <= dis[x][y] + 1) continue;
            if (dis[nx][ny] > dis[x][y] + 1) {
                dis[nx][ny] = dis[x][y] + 1;
                qu[++qt] = id(nx, ny);
            }
        }
    }
    return 0;
}

void initialize() {
    memset(fire, 0x7f, sizeof fire);
    memset(dis, 0x7f, sizeof dis);
}

int main() {
    for (scanf("%d", &T); T; --T) {
        initialize();
        scanf("%d%d", &R, &C);
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c) {
                while (isspace(map[r][c] = getchar()));
                if (map[r][c] == 'J') sx = r, sy = c;
            }
        qt = 0;
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
                if (map[r][c] == 'F') {
                    fire[r][c] = 0;
                    qu[qt++] = id(r, c);
                }
        bfs();
        int step = escape(sx, sy);
        if (!step) puts("IMPOSSIBLE");
        else printf("%d\n", step);
    }
    return 0;
}
