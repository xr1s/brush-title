#include <iostream>
using namespace std;

int n, s[60], t[60];
int kase;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (cin >> n; n; cin >> n) {
        for (int i = 0; i != n; ++i) cin >> s[i];
        for (int i = 0; i != n; ++i) cin >> t[i];
        cout << "Case " << ++kase << ": ";
        do --n; while (n != -1 && s[n] == t[n]);
        if (n != -1) {
            long long answer = 1;
            for (int i = n - 1, to = s[n] ^ t[n]; ~i; --i)
                if (s[i] != to) answer += 1ll << i, to ^= s[i];
            for (int i = n - 1, to = s[n] ^ t[n]; ~i; --i)
                if (t[i] != to) answer += 1ll << i, to ^= t[i];
            cout << answer << '\n';
        } else cout << "0\n";
    }
    return 0;
}
