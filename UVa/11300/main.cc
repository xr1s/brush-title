#include <iostream>
#include <algorithm>

using namespace std;

long long n, coin[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        long long ave = 0;
        for (int i = 1; i <= n; ++i)
            cin >> coin[i], ave += coin[i];
        ave /= n;
        for (int i = 1; i != n; ++i)
            coin[i] += coin[i - 1] - ave;
        nth_element(coin, coin + n / 2, coin + n);
        long long change = 0;
        for (int i = 0; i != n; ++i)
            change += abs(coin[i] - coin[n / 2]);
        cout << change << endl;
    }
    return 0;
}