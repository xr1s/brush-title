#include<iostream>
int main() {
  long n, m;
  while (std::cin >> n >> m && (n || m)) {
    if (n > m) std::swap(n, m);
    std::cout << (3 * n + m - 4) * n * m + 2 * n * (1 - n) * (1 + n) / 3 << '\n';
  }
}
