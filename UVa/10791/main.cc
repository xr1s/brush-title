#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int N, cs;

vector<int> factorize(int N) {
  vector<int> factor;
  if (N == 1) return {1};
  for (long long i = 2; i * i <= N; ++i)
    if (N % i == 0) {
      int p = 1;
      while (N % i == 0)
        p *= i, N /= i;
      factor.push_back(p);
    }
  if (N != 1)
    factor.push_back(N);
  return factor;
}

int main() {
  while (cin >> N && N) {
    cout << "Case " << ++cs << ": ";
    vector<int> factor = factorize(N);
    cout << accumulate(factor.begin(), factor.end(),
                       factor.size() == 1 ? 1LL : 0LL) << '\n';
  }
}
