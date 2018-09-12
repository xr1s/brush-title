#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n, p, q;

int main() {
  while (cin >> n >> p >> q)
    cout << (n % (p + q) && n % (p + q) <= p ? "LOST\n" : "WIN\n");
}
