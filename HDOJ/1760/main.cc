#include <unordered_map>
#include <iostream>
#include <bitset>
using namespace std;

int N, M;

int id(int r, int c) {
  return r * M + c;
}
unordered_map<bitset<50>, int> mem;

bool ok(const bitset<50> &bs, int r, int c) {
  return !bs.test(id(r, c))
      && !bs.test(id(r - 1, c))
      && !bs.test(id(r, c - 1))
      && !bs.test(id(r - 1, c - 1));
}

bitset<50> put(const bitset<50> &bs, int r, int c) {
  bitset<50> cp = bs;
  cp.set(id(r, c));
  cp.set(id(r - 1, c));
  cp.set(id(r, c - 1));
  cp.set(id(r - 1, c - 1));
  return cp;
}

int sg(const bitset<50> &bs) {
  auto it = mem.find(bs);
  if (it != mem.end()) return it->second;

  bitset<50> mex;
  for (int r = 1; r != N; ++r)
    for (int c = 1; c != M; ++c)
      if (ok(bs, r, c)) mex.set(sg(put(bs, r, c)));
  for (int i = 0; ; ++i)
    if (!mex.test(i)) return mem[bs] = i;
}

int main() {
  while (cin >> N >> M) {
    mem.clear();
    bitset<50> bs;
    for (int r = 0; r != N; ++r)
      for (int c = 0; c != M; ++c) {
        char bit; cin >> bit;
        bs[id(r, c)] = bit == '1';
      }
    cout << (sg(bs) ? "Yes\n" : "No\n");
  }
}
