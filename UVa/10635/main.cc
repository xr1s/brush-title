#include <algorithm>
#include <iterator>

template <typename ForwardIt>
size_t LongestIncreasingSequence(ForwardIt s, ForwardIt t) {
  typedef typename std::iterator_traits<ForwardIt>::value_type T;
  T *mono = new T[std::distance(s, t)];
  size_t size = 0;
  while (s != t) {
    T *repl = std::lower_bound(mono, mono + size, *s);
    if (repl == mono + size) ++size;
    *repl = *s++;
  }
  delete[] mono;
  return size;
}

template <typename ForwardIt, typename Compare>
size_t LongestIncreasingSequence(ForwardIt s, ForwardIt t, Compare comp) {
  typedef typename std::iterator_traits<ForwardIt>::value_type T;
  T *mono = new T[std::distance(s, t)];
  size_t size = 0;
  while (s != t) {
    T *repl = std::lower_bound(mono, mono + size, *s, comp);
    if (repl == mono + size) ++size;
    *repl = *s++;
  }
  delete[] mono;
  return size;
}

#include <iostream>
using namespace std;

int t, n, p, q, x[62505], y[62505];
int T;
int m[62505];

void init() {
  ++T;
  cin >> n >> p >> q;
  for (int i = 0; i <= p; ++i) cin >> x[i];
  for (int i = 0; i <= q; ++i) cin >> y[i];

  fill(m + 1, m + n * n + 1, 0);
  for (int i = 0; i <= q; ++i) m[y[i]] = i;
  for (int i = 0; i <= p; ++i) x[i] = m[x[i]];
}

void work() {
  cout << "Case " << T << ": " << LongestIncreasingSequence(x, x + p + 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (cin >> t; t; --t) {
    init();
    work();
  }
}
