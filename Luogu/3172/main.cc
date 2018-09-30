#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAXN 1000001
#define MOD 1000000007

template <size_t N> void
sieve(int mobius[]) {
  bitset<N> is_comp;
  vector<int> prime;
  mobius[1] = 1;
  for (int p = 2; p != N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (int q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        mobius[p * q] = 0;
        break;
      } else mobius[p * q] = -mobius[p];
    }
  }
}

int N, K, L, H;
int mobius[MAXN];

long psum(int n) {
  static unordered_map<int, long> mem;
  if (n < MAXN) return mobius[n];
  unordered_map<int, long>::iterator it;
  it = mem.find(n);
  if (it != mem.end())
    return it->second;
  long r = 1;
  for (int i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    r -= psum(n / i) * (j - i + 1) % MOD;
    if (r < 0) r += MOD;
  }
  return mem[n] = r;
}

long modpow(long b, int e) {
  long r = 1;
  do {
    if (e & 1) r = r * b % MOD;
    if (e > 1) b = b * b % MOD;
  } while (e >>= 1);
  return r;
}

int main() {
  sieve<MAXN>(mobius);
  for (int i = 0; i != MAXN; ++i) {
    mobius[i] = mobius[i] + mobius[i - 1];
    if (mobius[i] >= MOD) mobius[i] -= MOD;
    if (mobius[i] < 0) mobius[i] += MOD;
  }

  cin >> N >> K >> L >> H;
  H = H / K; L = (L - 1) / K;
  long r = 0;
  for (int i = 1, j; i <= H; i = j + 1) {
    if (L / i == 0) j = H / (H / i);
    else j = min(H / (H / i), L / (L / i));
    r += modpow(H / i - L / i, N) * (psum(j) - psum(i - 1)) % MOD;
    if (r >= MOD) r -= MOD;
    if (r < 0) r += MOD;
  }
  cout << r << '\n';
}
