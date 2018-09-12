#include <iostream>
#include <cstring>
using namespace std;

int T, kase;
char desc[16];
int n[3];
char s[50];
double c[2];

double surreal(char s[], int n) {
  double r = 0;
  int q = 0;
  while (q < n && s[q] == s[0])
    if (s[q++] == 'W') r += 1.; else r -= 1.;
  for (double k = .5; q < n; k /= 2.)
    if (s[q++] == 'W') r += k; else r -= k;
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for (cin >> T; T; --T) {
    c[0] = c[1] = 0.;
    cin >> desc >> desc;
    for (int i = 0; i != 2; ++i) {
      for (int j = 0; j != 3; ++j) cin >> n[j];
      for (int j = 0; j != 3; ++j) {
        for (int k = 0; k != n[j]; ++k) cin >> s[k];
        c[i] += surreal(s, n[j]);
      }
    }
    cout << "Test " << ++kase << ": ";
    cout << (c[0] >= c[1] ? "Yes\n" : "No\n");
  }
}
