#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int T;
double ax, ay, bx, by;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cout << fixed << setprecision(3);
  for (cin >> T; T; --T) {
    cin >> ax >> ay >> bx >> by;
    cout << hypot(ax + bx, ay + by) + hypot(ax - bx, ay - by) << '\n';
  }
}
