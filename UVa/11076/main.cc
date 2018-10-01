#include <algorithm>
#include <iostream>
using namespace std;

int N;
const int full_perm[] = {
  1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,
};
const long long sum_pow10[] = {
  0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111,
  11111111111, 111111111111,
};
int total[10];

int main() {
  while (cin >> N && N) {
    fill(total, total + 10, 0);
    for (int i = 0; i != N; ++i) {
      int d; cin >> d; ++total[d];
    }
    int perm = full_perm[N];
    for (int i = 0; i != 10; ++i)
      perm /= full_perm[total[i]];
    int sum = 0;
    for (int i = 0; i != 10; ++i)
      sum += perm * total[i] / N * i;
    cout << sum * sum_pow10[N] << '\n';
  }
}
