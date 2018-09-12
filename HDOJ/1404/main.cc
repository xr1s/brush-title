#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

bool mem[10000000];

void dfs(int n) {
  static const int p[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000,
  };
  int len = upper_bound(p, p + 7, n) - p;
  for (int i = 0; i != len; ++i) {
    int q = n / p[i] % 10;
    for (int j = 1; j != 10 - q; ++j)
      mem[n + j * p[i]] = true;
  }
  for (int i = 1; i <= 6 - len; ++i)
    memset(mem + n * p[i], true, p[i - 1]);
}

char s[10];

int main() {
  mem[0] = true;
  for (int i = 1; i != 1000000; ++i) if (!mem[i]) dfs(i);
  while (fgets(s, sizeof s, stdin))
    puts(*s == '0' || mem[atoi(s)] ? "Yes" : "No");
}
