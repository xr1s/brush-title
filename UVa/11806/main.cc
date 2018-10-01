#include <iostream>
using namespace std;

constexpr int mod = 1000007;
int T, N, M, K;
int C[505][505];

int binomial(int m, int n) {
  if (!**C) {
    for (int i = 0; i <= 500; ++i) C[i][0] = 1;
    for (int i = 1; i <= 500; ++i)
      for (int j = 1; j <= i; ++j) {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        if (C[i][j] >= mod) C[i][j] -= mod;
      }
  }
  return C[m][n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    cin >> N >> M >> K;
    int answer = binomial(N * M, K);
    answer -= binomial(N * (M - 1), K) * 2;
    answer -= binomial((N - 1) * M, K) * 2;
    answer += binomial(N * (M - 2), K);
    answer += binomial((N - 2) * M, K);
    answer += binomial((N - 1) * (M - 1), K) * 4;
    answer -= binomial((N - 1) * (M - 2), K) * 2;
    answer -= binomial((N - 2) * (M - 1), K) * 2;
    answer += binomial((N - 2) * (M - 2), K);
    if ((answer %= mod) < 0) answer += mod;
    cout << "Case " << cs << ": " << answer << '\n';
  }
}
