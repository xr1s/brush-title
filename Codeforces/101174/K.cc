#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct point {
    int x, y, z = 0;
} o = {0, 0, 0};

bool operator<(const point &lhs, const point &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    if (lhs.z != rhs.z) return lhs.z < rhs.z;
    return false;  // lhs == rhs
}

bool operator==(const point &lhs, const point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

using adj_list = map<point, set<point>>;

int n;
adj_list g3, g2;
map<point, bool> v3, v2;

bool dfs(const point &s, const point &p, adj_list &g, map<point, bool> &vis) {
    vis[s] = true;
    for (auto &to: g[s]) {
        if (to == p) continue;
        if (vis[to]) return true;
        if (dfs(to, s, g, vis)) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d%d%d", &x1, &y1, &z1);
        scanf("%d%d%d", &x2, &y2, &z2);
        if (x1 != x2 || y1 != y2 || z1 != z2) {
            g3[{x1, y1, z1}].insert({x2, y2, z2});
            g3[{x2, y2, z2}].insert({x1, y1, z1});
        }
        v3[{x1, y1, z1}] = v3[{x2, y2, z2}] = false;
        if (x1 != x2 || y1 != y2) {
            g2[{x1, y1}].insert({x2, y2});
            g2[{x2, y2}].insert({x1, y1});
        }
        v2[{x1, y1}] = v2[{x2, y2}] = false;
    }
    bool loop3 = false, loop2 = false;
    for (auto &ball: g3) {
        if (loop3) break;
        if (v3[ball.first]) continue;
        loop3 |= dfs(ball.first, o, g3, v3);
    }
    printf(loop3 ? "T" : "No t");
    puts("rue closed chains");
    for (auto &ball: g2) {
        if (loop2) break;
        if (v2[ball.first]) continue;
        loop2 |= dfs(ball.first, o, g2, v2);
    }
    printf(loop2 ? "F" : "No f");
    puts("loor closed chains");
    return 0;
}
