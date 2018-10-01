#include <iostream>
using namespace std;

constexpr int mod = 1'000'000;
int binom[200][200];

void prep() {
  for (int i = 0; i != 200; ++i) binom[i][0] = 1;
  for (int i = 1; i != 200; ++i)
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
      if (binom[i][j] >= mod) binom[i][j] -= mod;
    }
}

int N, K;

int main() {
  prep();
  while (cin >> N >> K && (N || K))
    cout << binom[N + K - 1][K - 1] << '\n';
}
