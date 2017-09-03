#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed << setprecision(4);
    while (cin >> n >> m) {
        long double move = 0.l;
        for (int i = 0; i != n; ++i) {
            long double place = 1.l * i * (n + m) / n;
            move += abs(place - round(place));
        }
        cout << 10000.l * move / (n + m) << '\n';
    }
    return 0;
}
