#include <cstdio>
using namespace std;

int T, n, a[100005], b[100005];
const char *winner[2]{"Bob", "Alice"};

bool work() {
  scanf("%d", &n);
  for (int i = 0; i != n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i != n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i != n; ++i)
    if (a[i] == 1 && b[i] == 1) b[i] = 0;

  int cons[3]{0, 0, 0};
  bool exchg = false;
  for (int i = 0; i != n; ++i) ++cons[b[i]];
  if (cons[1] + cons[2] > 1) return false;
  if (cons[1] + cons[2] == 1) {
    for (int i = 0; i != n; ++i) {
      if (b[i] == 2 && a[i] % 2 == 1) return false;
      if (b[i] == 2 && a[i] % 2 == 0) a[i] = 0;
      if (b[i] == 1) a[i] = a[i] & 1 ^ 1;
    }
    exchg = true;
  }

  int sg = 0;
  for (int i = 0; i != n; ++i) sg ^= a[i];
  return !!sg ^ exchg;
}

int main() {
  for (scanf("%d", &T); T; --T) puts(work()[winner]);
}
