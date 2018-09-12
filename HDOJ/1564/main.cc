#include <iostream>
using namespace std;

int main() {
  for (int n; cin >> n && n; )
    cout << (const char *[]){"8600\n", "ailyanlu\n"}[n & 1];
}
