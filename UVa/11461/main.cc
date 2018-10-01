#include <cmath>
#include <iostream>
using namespace std;

int a, b;

int main() {
  while (cin >> a >> b && (a || b))
    cout << (int)sqrt(b) - (int)sqrt(a - 1) << '\n';
}
