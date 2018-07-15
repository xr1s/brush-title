#include <cstdio>
#include <cstring>

template <typename Iter, typename T>
void generatePMT(Iter begin, Iter end, T *pmt) {
  size_t len = end - begin;
  if (len == 0) return;
  *pmt = -1;
  for (T i = 0, j = -1; i < len - 1; ) {
    if (j == -1 || begin[i] == begin[j]) {
      pmt[++i] = ++j;
      /*
      if (pmt[++i] != pmt[++j]) {
        pmt[i] = pmt[j];
      } else {
        pmt[i] = j;
      }
      */
    } else j = pmt[j];
  }
}

int T;
char s[100005];
size_t pmt[sizeof s];

int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%s", s);
    int len = strlen(s);
    generatePMT(s, s + len + 1, pmt);
    int loop = len - pmt[len];
    if (pmt[len] == 0) printf("%d\n", len);
    else if (len % loop == 0) puts("0");
    else printf("%d\n", loop - len % loop);
  }
}
