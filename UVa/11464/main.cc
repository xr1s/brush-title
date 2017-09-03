#include <iostream>
#include <cstring>

using namespace std;

int T, N;
bool grid[20][20], flip[20][20];

inline bool neighbour(bool grid[20][20], int i, int j) {
    bool boolean = false;
    boolean ^= grid[i - 1][j];
    boolean ^= grid[i][j - 1];
    boolean ^= grid[i + 1][j];
    boolean ^= grid[i][j + 1];
    return boolean;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int answer = ~0u >> 1;
        cin >> N;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                cin >> grid[i][j];
        for (int i = 0; i != 2 << N; i += 2) {
            memset(flip, false, sizeof flip);
            for (int k = 1; k <= N; ++k)
                if (i & 1 << k) flip[1][k] = true;
            bool satisfied = true;
            for (int k = 1; satisfied && k <= N; ++k)
                satisfied &= !grid[1][k] || flip[1][k];
            for (int j = 2; satisfied && j <= N; ++j)
                for (int k = 1; satisfied && k <= N; ++k) {
                    flip[j][k] = neighbour(flip, j - 1, k);
                    satisfied &= !grid[j][k] || flip[j][k];
                }
            for (int k = 1; satisfied && k <= N; ++k)
                satisfied &= !neighbour(flip, N, k);
            if (!satisfied) continue;
            int modified = 0;
            for (int j = 1; j <= N; ++j)
                for (int k = 1; k <= N; ++k)
                    modified += grid[j][k] ^ flip[j][k];
            answer = min(answer, modified);
        }
        cout << "Case " << kase << ": ";
        if (answer == ~0u >> 1) cout << -1 << '\n';
        else cout << answer << '\n';
    }
    return 0;
}
