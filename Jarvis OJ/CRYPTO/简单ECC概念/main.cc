#include <iostream>
#include "elliptic_curve.hh"

int main() {
    elliptic_curve ec(16546484, 4548674875, 15424654874903);
    elliptic_point G = ec.at(6478678675, 5636379357093);
    std::cout << 546768 * G << std::endl;
    return 0;
}
