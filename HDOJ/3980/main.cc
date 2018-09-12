#include <bitset>
#include <cstring>
#include <iostream>
using namespace std;

int T, M, N;
int mem[1001];
int kase;

int sg(int n) {
  if (mem[n] != -1) return mem[n];
  bitset<1001> mex;
  for (int i = 0; i <= n - M >> 1; ++i)
    mex.set(sg(i) ^ sg(n - M - i));
  for (int i = 0; ; ++i)
    if (!mex.test(i)) return mem[n] = i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  for (cin >> T; T; --T) {
    cin >> N >> M;
    memset(mem, 0xff, sizeof mem);
    cout << "Case #" << ++kase << ": ";
    cout << (N < M || sg(N - M) ? "abcdxyzk\n" : "aekdycoin\n");
  }
}
