#include <tuple>

template <typename T,
        typename = typename std::enable_if<std::is_integral<T>::value>::type>
std::tuple<T, T, T> exgcd(T m, T n) {
    T x = 0, y = 1, xp = 1, yp = 0, xt, yt;
    for (T r = m % n, q = m / n; r; ) {
        xt = xp - q * x, xp = x, x = xt;
        yt = yp - q * y, yp = y, y = yt;
        m = n, n = r, r = m % n, q = m / n;
    }
    return std::make_tuple(n, x, y);
}

template <typename T,
        typename = typename std::enable_if<std::is_integral<T>::value>::type>
T modinv(T m, T n) {
    T gcd, inv, _, loop;
    std::tie(gcd, inv, _) = exgcd(m, n);
    loop = n / gcd;
    return (inv % loop + loop) % loop;
}

#include <iostream>
using namespace std;

int T, a, m, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T; --T) {
        cin >> a >> m;
        if (m == 1) {
            cout << "1\n";  // zoj says 1
            continue;
        }
        x = modinv(a, m);
        if (a * x % m == 1) cout << x << '\n';
        else cout << "Not Exist\n";
    }
    return 0;
}
