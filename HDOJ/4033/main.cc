#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

constexpr long double pi = acosl(-1.l);

int T, N;
long double d[105];
long double alpha;

int match(long double len) {
    long double l = len / (2.l * sinl(alpha / 2.l));
    long double area = l * l * sinl(alpha) * N / 2.l;
    long double partial = 0.l;
    for (int i = 0; i != N; ++i) {
        int j = (i + 1) % N;
        long double p = (d[i] + d[j] + len) / 2.l;
        partial += sqrtl(p * (p - d[i]) * (p - d[j]) * (p - len));
    }
    if (abs(partial - area) <= 1e-6) return 0;
    else if (partial > area) return +1;
    else if (partial < area) return -1;
}

int main() {
    cout << fixed << setprecision(3);
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> N;
        for (int i = 0; i != N; ++i) cin >> d[i];
        alpha = 2.l * pi / N;
        long double l = 0.l, r = 20000.l;
        for (int i = 0; i != N; ++i) {
            int j = (i + 1) % N;
            r = min(r, d[i] + d[j]);
            l = max(l, abs(d[i] - d[j]));
        }
        long double m = (l + r) / 2.l;
        bool find = false;
        while (abs(l - r) > 1e-6 && !find) {
            switch (match(m)) {
                case -1: r = m; break;
                case 0: find = true; break;
                case +1: l = m; break;
            }
            if (find) break;
            m = (l + r) / 2.l;
        }
        bool flag = true;
        for (int i = 0; i != N; ++i) {
            int j = (i + 1) % N;
            if (d[i] + d[j] <= m + 1e-5 || abs(d[i] - d[j]) >= m - 1e-5) {
                flag = false;
                break;
            }
        }
        cout << "Case " << kase << ": ";
        if (flag) cout << m << '\n';
        else cout << "impossible\n";
    }
    return 0;
}
