#include <bitset>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N;
bitset<26> S[25];

void init() {
  string s;
  for (int i = 0; i != N; ++i) {
    cin >> s;
    S[i].reset();
    for (char c: s)
      S[i].flip(c - 'A');
  }
}

void work() {
  int n = N / 2, m = N - n;
  unordered_map<bitset<26>, bitset<24>> um;
  bitset<24> answer;

  for (int i = 0; i != 1 << n; ++i) {
    bitset<24> bs = i;
    bitset<26> sum;
    for (int j = 0; j != n; ++j)
      if (bs.test(j)) sum ^= S[j];
    auto it = um.find(sum);
    if (it != um.end()) {
      if (bs.count() > it->second.count())
        it->second = bs;
    } else um[sum] = bs;
  }
  for (int i = 0; i != 1 << m; ++i) {
    bitset<24> bs = i << n;
    bitset<26> sum;
    for (int j = n; j != N; ++j)
      if (bs.test(j)) sum ^= S[j];
    auto it = um.find(sum);
    if (it == um.end()) continue;
    if (it->second.count() + bs.count() > answer.count())
      answer = bs | it->second;
  }

  int total = answer.count();
  cout << total << '\n';
  for (int i = 0; i != N; ++i)
    if (answer.test(i)) cout << i + 1 << " \n"[--total == 0];
  if (N == 1) cout << '\n';
}

int main() {
  while (cin >> N) {
    init();
    work();
  }
}
