#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    cout << (const char *[]){"Kiki\n", "Cici\n"}[n % 3 == 0];
  }
}
