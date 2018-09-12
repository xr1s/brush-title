#include <iostream>
using namespace std;

int xp, yp, xv, yv;

int main() {
  cin >> xp >> yp >> xv >> yv;
  if (xp <= xv && yp <= yv) {
    cout << "Polycarp\n";
  } else if (xp >= xv && yp >= yv) {
    cout << "Vasiliy\n";
  } else {
    int sp = xp + yp;
    int sv = max(xv, yv);
    cout << (sp <= sv ? "Polycarp\n" : "Vasiliy\n");
  }
}
