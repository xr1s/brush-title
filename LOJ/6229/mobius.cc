#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
using namespace std;

constexpr long maxn = 1000001;
constexpr long mod = 1000000007;

long S[maxn];

template <size_t N> void
sieve() {
  vector<long> prime;
  bitset<N> is_comp;
  S[1] = 1;
  for (long p = 2; p != N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      S[p] = 1 - p * p % mod;
      if (S[p] < 0) S[p] += mod;
    }
    for (long q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        S[p * q] = S[p];
        break;
      } else S[p * q] = S[p] * S[q] % mod;
    }
  }
}

long sumsq(long n) {
  return n * (n + 1) % mod * (2 * n + 1) % mod * 166666668 % mod;
}

long psum(long n) {
  static unordered_map<long, long> mem;
  if (n < maxn) return S[n];
  const auto m = mem.find(n);
  if (m != mem.end()) return m->second;
  long r = n;
  for (long i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    long diff = sumsq(j) - sumsq(i - 1);
    if (diff < 0) diff += mod;
    r -= diff * psum(n / i) % mod;
    if (r < 0) r += mod;
  }
  return mem[n] = r;
}

long solve(long n) {
  long sum = 0;
  for (long i = 1, j; i <= n; i = j + 1) {
    const long ni = n / i;
    const long Sn = ni * (ni + 1) / 2 % mod;
    j = n / ni;
    sum += Sn * Sn % mod * (psum(j) - psum(i - 1) + mod) % mod;
    if (sum >= mod) sum -= mod;
  }
  return (sum + n) * 500000004 % mod;
}

long T, n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  sieve<maxn>();
  for (long i = 1; i != maxn; ++i)
    if ((S[i] += S[i - 1]) >= mod) S[i] -= mod;

  cin >> n;
  cout << solve(n) << '\n';
}
