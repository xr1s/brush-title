#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n && n)
    cout << (n & 1 ? "Bob\n" : "Alice\n");
}
