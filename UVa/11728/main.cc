#include <iostream>
using namespace std;

int T, S;
int answer[3080];

int main() {
  fill(begin(answer), end(answer), -1);
  for (int i = 1; i <= 1000; ++i) {
    int p = 1, sum = 0;
    for (; p * p < i; ++p)
      if (i % p == 0) sum += p + i / p;
    if (p * p == i) sum += p;
    answer[sum] = i;
  }

  while (cin >> S && S)
    cout << "Case " << ++T << ": " << answer[S] << '\n';
}
