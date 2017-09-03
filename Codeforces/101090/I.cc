#include <iostream>
using namespace std;

int main() {
    int chr, i, n;
    string str, sub;
    for (chr = '0'; chr <= '9'; ++chr, str += sub + str)
        for (sub.clear(), i = 0; i <= str.length(); ++i) sub += chr;
    cin >> n;
    cout << str.substr(0, n) << endl;
    return 0;
}
