#include <iostream>
#include <algorithm>

using namespace std;

int n, m, d[20005], h[20005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> n >> m; n || m; cin >> n >> m) {
        for (int i = 0; i != n; ++i) cin >> d[i];
        for (int j = 0; j != m; ++j) cin >> h[j];
        sort(d, d + n); sort(h, h + m);
        int i = 0, j = 0, payment = 0;
        while (i != n && j != m) {
            while (j != m && d[i] > h[j]) ++j;
            payment += h[j++]; ++i;
        }
        if (i == n) cout << payment << '\n';
        else cout << "Loowater is doomed!\n";
    }
    return 0;
}