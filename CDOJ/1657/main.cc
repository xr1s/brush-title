#include <iostream>
#include <string>
using namespace std;

string emoji;

int main() {
    while (cin >> emoji) {
        cout << ":fan::fan::fan:" << endl;
        cout << ":fan::" << emoji << "::fan:" << endl;
        cout << ":fan::fan::fan:" << endl;
    }
    return 0;
}
