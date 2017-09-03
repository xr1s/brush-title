#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n)
        cout << (int)log2(n) + 1 << '\n';
    return 0;
}
