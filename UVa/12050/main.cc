#include <iostream>
#include <string>
using namespace std;

int main() {
  long long i;
  while (cin >> i && i) {
    long long psum = 0, pow10 = 1;
    while (psum + pow10 * 18 < i) {
      psum += pow10 * 18;
      pow10 *= 10;
    }
    string value;
    if (i - psum <= pow10 * 9) {
      value = to_string(i - psum + pow10 - 1);
      value.append(value.rbegin() + 1, value.rend());
    } else {
      value = to_string(i - psum - pow10 * 8 - 1);
      value.append(value.rbegin(), value.rend());
    }
    cout << value << '\n';
  }
}
