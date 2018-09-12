#include <iostream>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && (n || m))
    cout << (const char *[]){"Wonderful!\n", "What a pity!\n"}[n & 1 && m & 1];
}
