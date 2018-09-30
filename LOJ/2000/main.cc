#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

constexpr int mod = 1000000007;

template <size_t N> void
sieve(int mobius[]) {
  vector<int> prime;
  prime.reserve(78498);
  bitset<N> is_comp;
  mobius[1] = 1;
  for (int p = 2; p < N; ++p) {
    if (!is_comp.test(p)) {
      prime.push_back(p);
      mobius[p] = -1;
    }
    for (long long q: prime) {
      if (p * q >= N) break;
      is_comp.set(p * q);
      if (p % q == 0) {
        mobius[p * q] = 0;
        break;
      } else mobius[p * q] = -mobius[p];
    }
  }
}

template <typename B, typename E>
B modpow(B base, E expo, B mod) {
  B retn = 1;
  do {
    if (expo & 1) retn = retn * base % mod;
    if (expo ^ 1) base = base * base % mod;
  } while (expo >>= 1);
  return retn;
}

template <typename T>
std::pair<T, std::pair<T, T> > exgcd(T m, T n) {
    using std::make_pair;
    T x = 0, y = 1, xp = 1, yp = 0, xt, yt;
    for (T r = m % n, q = m / n; r; ) {
        xt = xp - q * x, xp = x, x = xt;
        yt = yp - q * y, yp = y, y = yt;
        m = n, n = r, r = m % n, q = m / n;
    }
    return make_pair(n, make_pair(x, y));
}

template <typename T>
T modinv(T m, T n) {
  typedef std::pair<T, std::pair<T, T> > triple;
  triple gxy = exgcd(m, n);
  T loop = n / gxy.first;
  T inv = gxy.second.first;
  inv = inv % loop;
  return inv < 0 ? inv + loop : inv;
}

int T, n, m;
int mobi[1000005];
int fibo[1000005], finv[1000005];
int prod[1000005], pinv[1000005];

void prep() {
  sieve<1000001>(mobi);
  fibo[0] = 0; fibo[1] = 1;
  for (int i = 2; i <= 1000000; ++i) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
    if (fibo[i] >= mod) fibo[i] -= mod;
  }
  for (int i = 1; i <= 1000000; ++i)
    finv[i] = modinv<int64_t>(fibo[i], mod);
  fill(begin(prod), end(prod), 1);
  for (int k = 1; k <= 1000000; ++k)
    for (int r = 1; r <= 1000000 / k; ++r) {
      if (mobi[r] == +1)
        prod[k * r] = (int64_t)prod[k * r] * fibo[k] % mod;
      if (mobi[r] == -1)
        prod[k * r] = (int64_t)prod[k * r] * finv[k] % mod;
    }
  for (int i = 1; i != 1000000; ++i) {
    prod[i] = (int64_t)prod[i] * prod[i - 1] % mod;
    pinv[i] = modinv<int64_t>(prod[i], mod);
  }
  pinv[0] = 1;
}

int solve(int m, int n) {
  int r = 1;
  for (int i = 1, j; i <= min(m, n); i = j + 1) {
    j = min(m / (m / i), n / (n / i));
    const int b = (int64_t)prod[j] * pinv[i - 1] % mod;
    const int e = (int64_t)(n / i) * (m / i) % (mod - 1);
    r = r * modpow<int64_t>(b, e, mod) % mod;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  prep();
  for (cin >> T; T; --T) {
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
}
