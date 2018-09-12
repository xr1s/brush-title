#include <algorithm>
#include <iostream>
using namespace std;

int n, pile[105];
string line;

bool work() {
  cin.get();
  if (n % 2) {
    getline(cin, line);
    return true;
  }
  for (int i = 0; i != n; ++i) cin >> pile[i];
  sort(pile, pile + n);
  bool win = false;
  for (int i = 0; i != n; i += 2)
    win |= pile[i] != pile[i + 1];
  return win;
}

int main() {
  while (cin >> n && n)
    cout.put(work()["01"]).put('\n');
}
