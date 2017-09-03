#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const long double pi = acosl(-1.l);

int T, n;
long double R;

int main() {
    cout << fixed << setprecision(7);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> R >> n;
        cout << "Case " << i << ": ";
        cout << R / (sqrtl(2.l / (1.l - cosl(2.l * pi / n))) + 1.l) << '\n';
    }
    return 0;
}
