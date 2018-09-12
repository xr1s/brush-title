#include <cstdint>
#include <algorithm>
#include <iostream>
using namespace std;

using i64 = int64_t;
using vec = pair<i64, i64>;
#define x first
#define y second

constexpr i64 mod = 110119;

i64 T, n, m, r;
i64 inv[mod], fact[mod], finv[mod];
vec obs[105];
i64 dp[105];

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
  std::pair<T, std::pair<T, T> > gxy = exgcd(m, n);
  T loop = n / gxy.first;
  T inv = gxy.second.first;
  inv = inv % loop;
  return inv < 0 ? inv + loop : inv;
}

template <typename T>
T binomial(T m, T n, T p) {
  T r = 1;
  do {
    T mp = m % p, np = n % p;
    if (mp < np) return 0;
    r = r * fact[mp] % p * finv[np] % p * finv[mp - np] % p;
  } while ((m /= p) && (n /= p));
  return r;
}

void prep() {
  for (int i = 1; i != mod; ++i)
    inv[i] = modinv(static_cast<i64>(i), mod);
  fact[0] = 1;
  for (int i = 1; i != mod; ++i)
    fact[i] = fact[i - 1] * i % mod;
  for (int i = 0; i != mod; ++i)
    finv[i] = inv[fact[i]];
}

void init() {
  ++T;
  for (int i = 0; i != r; ++i)
    cin >> obs[i].x >> obs[i].y;
  sort(obs, obs + r);
  obs[r].x = n; obs[r].y = m;
}

i64 approaches(i64 dx, i64 dy) {
  if (dx < 0 || dy < 0) return 0;
  if ((dx + dy) % 3 != 0) return 0;
  i64 h = (2 * dx - dy) / 3;
  i64 v = (2 * dy - dx) / 3;
  if (h < 0 || v < 0) return 0;
  return binomial(h + v, v, mod);
}

void work() {
  for (int i = 0; i <= r; ++i) {
    dp[i] = approaches(obs[i].x - 1, obs[i].y - 1);
    for (int j = 0; j < i; ++j) {
      const i64 dx = obs[i].x - obs[j].x;
      const i64 dy = obs[i].y - obs[j].y;
      dp[i] -= dp[j] * approaches(dx, dy) % mod;
      if (dp[i] < 0) dp[i] += mod;
    }
  }
  cout << "Case #" << T << ": " << dp[r] << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  prep();

  while (cin >> n >> m >> r) {
    init();
    work();
  }
}
