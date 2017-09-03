#include <iostream>
#include <algorithm>

using namespace std;

struct ant {
    int id, p;
} a[10005];

struct dot {
    int pos;
    char dir;
} x[10005];

int N, L, T, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int kase = 1; kase <= N; ++kase) {
        cin >> L >> T >> n;
        for (int i = 0; i != n; ++i) {
            cin >> x[i].pos >> x[i].dir;
            a[i].id = i; a[i].p = x[i].pos;
            switch (x[i].dir) {
              case 'L': x[i].pos -= T; break;
              case 'R': x[i].pos += T; break;
            }
        }
        sort(x, x + n, [](const dot &lhs, const dot &rhs) {
            return lhs.pos < rhs.pos;
        });
        sort(a, a + n, [](const ant &lhs, const ant &rhs) {
            return lhs.p < rhs.p;
        });
        for (int i = 0; i != n; ++i) a[i].p = i;
        sort(a, a + n, [](const ant &lhs, const ant &rhs) {
            return lhs.id < rhs.id;
        });
        cout << "Case #" << kase << ":\n";
        for (int i = 0; i != n; ++i)
            if (0 <= x[a[i].p].pos && x[a[i].p].pos <= L) {
                int current = x[a[i].p].pos;
                cout << current << ' ';
                if (a[i].p != 0 && current == x[a[i].p - 1].pos) {
                    cout << "Turning\n"; continue;
                }
                if (a[i].p + 1 != n && current == x[a[i].p + 1].pos) {
                    cout << "Turning\n"; continue;
                }
                cout << x[a[i].p].dir << '\n';
            } else cout << "Fell off\n";
        cout << '\n';
    }
    return 0;
}