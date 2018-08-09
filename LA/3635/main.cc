#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

constexpr double pi = M_PI;
constexpr double eps = 1e-4;

int T, N, F;
double v[10005], V;

void init() {
  cin >> N >> F;
  V = 0;
  for (int i = 0; i != N; ++i) {
    int ri; cin >> ri;
    v[i] = ri * ri * pi;
    V += v[i];
  }
}

bool check(double m) {
  int total = 0;
  for (int i = 0; i != N; ++i)
    total += floor(v[i] / m);
  return total <= F;
}

void work() {
  double bnd[2] = {0, V};
  while (abs(bnd[0] - bnd[1]) >= eps) {
    double m = (bnd[0] + bnd[1]) / 2;
    bnd[check(m)] = m;
  }
  cout << fixed << setprecision(4) << *bnd << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  for (cin >> T; T; --T) {
    init();
    work();
  }
}
