#include <bitset>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <size_t N>
bitset<N> sieve() {
  bitset<N> is_comp;
  vector<int> prime;
  for (int p = 2; p != N; ++p) {
    if (!is_comp.test(p))
      prime.push_back(p);
    for (int q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) break;
    }
  }
  return is_comp;
}

const bitset<64> is_comp = sieve<64>();
set<unsigned long long> answers;

int main() {
  ios_base::sync_with_stdio(false);
  for (int base = 2; base != 1 << 16; ++base) {
    unsigned long long p = 1ULL;
    unsigned long long l = ~0ULL;
    for (int i = 0; l; ++i) {
      if (is_comp.test(i))
        answers.insert(p);
      p *= base; l /= base;
    }
  }
  cout << "1\n";
  for (unsigned long long answer: answers)
    cout << answer << '\n';
}
