#include <iostream>
#include <string>
using namespace std;

int T;
string N;

int main() {
  N.reserve(1005);
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int total[3] = {0};
    cin >> N;
    for (char c: N)
      ++total[(c - '0') % 3];
    int ds = total[1] + total[2] * 2;
    cout << "Case " << cs << ": ";
    if (total[ds % 3]) {
      --total[ds-- % 3];
      cout.put("ST"[*total & 1]);
    } else cout.put('T');
    cout.put('\n');
  }
}
