#include <cstring>
#include <iostream>
#include <tuple>

using namespace std;

int n;
char view[6][10][10];
char cube[10][10][10];

tuple<int, int, int> coor(int s, int x, int y, int z) {
    switch (s) {
      case 0: return {x, y, z};                  // 前
      case 1: return {x, z, n - 1 - y};          // 左
      case 2: return {x, n - 1 - y, n - 1 - z};  // 后
      case 3: return {x, n - 1 - z, y};          // 右
      case 4: return {z, y, n - 1 - x};          // 顶
      case 5: return {n - 1 - z, y, x};          // 底
    }
}

void print_cube() {
    for (int z = 0; z != n; ++z) {
        for (int x = 0; x != n; ++x) {
            for (int y = 0; y != n; ++y)
                clog << cube[x][y][z];
            clog << endl;
        }
        clog << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (cin >> n; n; cin >> n) {
        for (int i = 0; i != n; ++i)
            for (int s = 0; s != 6; ++s)
                for (int j = 0; j != n; ++j)
                    cin >> view[s][i][j];
        for (int x = 0; x != n; ++x)
            for (int y = 0; y != n; ++y)
                for (int z = 0; z != n; ++z)
                    cube[x][y][z] = '#';
        for (int s = 0; s != 6; ++s)
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != n; ++j)
                    if (view[s][i][j] == '.')
                        for (int k = 0; k != n; ++k) {
                            int x, y, z;
                            tie(x, y, z) = coor(s, i, j, k);
                            cube[x][y][z] = ' ';
                        }
        for (bool work = true; work; ) {
            work = false;
            for (int s = 0; s != 6; ++s)
                for (int i = 0; i != n; ++i)
                    for (int j = 0; j != n; ++j)
                        if (view[s][i][j] != '.')
                            for (int k = 0; k != n; ++k) {
                                int x, y, z;
                                tie(x, y, z) = coor(s, i, j, k);
                                if (cube[x][y][z] == ' ') continue;
                                if (cube[x][y][z] == view[s][i][j]) break;
                                if (cube[x][y][z] == '#') {
                                    cube[x][y][z] = view[s][i][j];
                                    break;
                                }
                                cube[x][y][z] = ' ';
                                work = true;
                            }
        }
        int weight = 0;
        for (int x = 0; x != n; ++x)
            for (int y = 0; y != n; ++y)
                for (int z = 0; z != n; ++z)
                    if (cube[x][y][z] != ' ')
                        ++weight;
        cout << "Maximum weight: " << weight << " gram(s)\n";
    }
    return 0;
}
