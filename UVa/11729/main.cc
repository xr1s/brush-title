#include <iostream>
#include <algorithm>

using namespace std;

struct job {
    int J, B;
} soldier[1005];
int N, kase;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> N; N; cin >> N) {
        for (int i = 0; i != N; ++i)
            cin >> soldier[i].B >> soldier[i].J;
        sort(soldier, soldier + N, [](const job &lhs, const job &rhs) {
            return lhs.J > rhs.J;
        });
        int last = 0;
        for (int i = 0, t = 0; i != N; ++i)
            last = max(last, (t += soldier[i].B) + soldier[i].J);
        cout << "Case " << ++kase << ": " << last << '\n';
    }
    return 0;
}