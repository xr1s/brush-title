#include <string>
#include <iostream>
using namespace std;

int N;
int timestamp;
string line, output;

int main() {
    for (cin >> N, getline(cin, line); N; --N) {
        timestamp = 0; output = "";
        while (getline(cin, line)) {
            ++timestamp;
            if (line == "END OF CASE") break;
            for (auto &it: line) {
                if (it == ';') {
                    cout << timestamp << ": ";
                    cout << output << ';' << '\n';
                    output = "";
                } else output += it;
            }
        }
    }
    return 0;
}
