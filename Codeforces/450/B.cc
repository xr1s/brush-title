#include <algorithm>  // std::swap
#include <utility>  // std::pair, std::make_pair

// Stein's Algorithm
// 1 time faster than std::gcd
template <typename T>
T gcd(T m, T n) {
  if (!m || !n) return m | n;
  if (m < 0) m = -m;
  if (n < 0) n = -n;
  int p = 0;
  while (!(m & 1) && !(n & 1))
    m >>= 1, n >>= 1, ++p;
  while (n) {
    while (!(m & 1)) m >>= 1;
    while (!(n & 1)) n >>= 1;
    if (m >= n) std::swap(m, n);
    n = (n - m) >> 1;
  }
  return m << p;
}

// mx + ny = gcd(m, n)
// return: (gcd, x, y)
// r.first is gcd
// r.second.first  is x
// r.second.second is y
// C++98 has no std::tuple, put up with it.
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
  typedef std::pair<T, std::pair<T, T> > t3i;
  t3i gxy = exgcd(m, n);
  T loop = n / gxy.first;
  T inv = gxy.second.first;
  inv = inv % loop + loop;
  return inv < loop ? inv : inv - loop;
}

#include <iostream>  // std::istream, std::ostream

template <typename T, T = 0> class Residue;

template <typename T, T Mod>
std::ostream &operator<<(std::ostream &, const Residue<T, Mod> &);
template <typename T, T Mod>
std::istream &operator>>(std::istream &, Residue<T, Mod> &);

template <typename T, T Mod> Residue<T, Mod> &
operator+=(Residue<T, Mod> &, const Residue<T, Mod> &);
template <typename T, T Mod> Residue<T, Mod> &
operator-=(Residue<T, Mod> &, const Residue<T, Mod> &);
template <typename T, T Mod> Residue<T, Mod> &
operator*=(Residue<T, Mod> &, const Residue<T, Mod> &);
template <typename T, T Mod> Residue<T, Mod> &
operator/=(Residue<T, Mod> &, const Residue<T, Mod> &);
template <typename T, T Mod> Residue<T, Mod> &
operator/=(Residue<T, Mod> &, const Residue<T, Mod> &);

template <typename T, T Mod>
class Residue {
 public:
  Residue();
  Residue(const Residue &);
  Residue(const T &);

  friend std::ostream &operator<<<>(std::ostream &, const Residue &);
  friend std::istream &operator>><>(std::istream &, Residue &);
  friend Residue &operator+=<>(Residue &, const Residue &);
  friend Residue &operator-=<>(Residue &, const Residue &);
  friend Residue &operator*=<>(Residue &, const Residue &);
  friend Residue &operator/=<>(Residue &, const Residue &);

 private:
  T value;
};

template <typename T, T Mod>
Residue<T, Mod>::Residue()
    : value(0) {
}

template <typename T, T Mod>
Residue<T, Mod>::Residue(const T &value)
    : value(value % Mod) {
  if (this->value < 0)
    this->value += Mod;
}

template <typename T, T Mod>
Residue<T, Mod>::Residue(const Residue &that)
    : value(that.value) {
}

template <typename T, T Mod> std::ostream &
operator<<(std::ostream &os, const Residue<T, Mod> &self) {
  return os << self.value;
}

template <typename T, T Mod> std::istream &
operator>>(std::istream &is, Residue<T, Mod> &self) {
  is >> self.value;
  self.value %= Mod;
  if (self.value < 0)
    self.value += Mod;
  return is;
}

template <typename T, T Mod> Residue<T, Mod> &
operator+=(Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  if ((lhs.value += rhs.value) >= Mod)
    lhs.value -= Mod;
  return lhs;
}

template <typename T, T Mod> Residue<T, Mod> &
operator+=(Residue<T, Mod> &lhs, const T &rhs) {
  return lhs += Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod>
operator+(const Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  Residue<T, Mod> copy = lhs;
  return copy += rhs;
}

template <typename T, T Mod> Residue<T, Mod>
operator+(const Residue<T, Mod> &lhs, const T &rhs) {
  return lhs + Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod> &
operator-=(Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  if ((lhs.value -= rhs.value) < 0)
    lhs.value += Mod;
  return lhs;
}

template <typename T, T Mod> Residue<T, Mod> &
operator-=(Residue<T, Mod> &lhs, const T &rhs) {
  return lhs -= Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod>
operator-(const Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  Residue<T, Mod> copy = lhs;
  return copy -= rhs;
}

template <typename T, T Mod> Residue<T, Mod>
operator-(const Residue<T, Mod> &lhs, const T &rhs) {
  return lhs - Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod> &
operator*=(Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  lhs.value *= rhs.value;
  lhs.value %= Mod;
  return lhs;
}

template <typename T, T Mod> Residue<T, Mod> &
operator*=(Residue<T, Mod> &lhs, const T &rhs) {
  return lhs *= Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod>
operator*(const Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  Residue<T, Mod> copy = lhs;
  return copy *= rhs;
}

template <typename T, T Mod> Residue<T, Mod>
operator*(const Residue<T, Mod> &lhs, const T &rhs) {
  return lhs * Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod> &
operator/=(Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  lhs.value *= modinv(rhs.value, Mod);
  lhs.value %= Mod;
  return lhs;
}

template <typename T, T Mod> Residue<T, Mod> &
operator/=(Residue<T, Mod> &lhs, const T &rhs) {
  return lhs /= Residue<T, Mod>(rhs);
}

template <typename T, T Mod> Residue<T, Mod>
operator/(const Residue<T, Mod> &lhs, const Residue<T, Mod> &rhs) {
  Residue<T, Mod> copy = lhs;
  return copy /= rhs;
}

template <typename T, T Mod> Residue<T, Mod>
operator/(const Residue<T, Mod> &lhs, const T &rhs) {
  return lhs / Residue<T, Mod>(rhs);
}

using namespace std;

int main() {
  Residue<long long, 1000000007> x, y, z;
  long long n;
  cin >> x >> y >> n;
  for (n = (n - 1) % 6; n; --n) {
    x = exchange(y, y - x);
  }
  cout << x << endl;
}
