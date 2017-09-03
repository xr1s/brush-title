#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int n;
string course[15], word;
string weekday[15];
int col[15], row[15];
string table[5][5][10];
int height[5][5];
int maxh[5] = { 1, 1, 1, 1, 1 };

const string delimiter = "+----------+----------+----------+\n";

int main() {
    cin >> n;
    for (int i = 0; i != n; ++i) {
        getline(cin, word);
        getline(cin, course[i]);
        cin >> weekday[i] >> col[i]; --col[i];
        if (weekday[i] == "Tuesday")  row[i] = 0;
        if (weekday[i] == "Thursday") row[i] = 1;
        if (weekday[i] == "Saturday") row[i] = 2;
    }
    for (int i = 0; i != n; ++i) {
        stringstream ss(course[i]);
        int c = col[i], r = row[i], h = 0;
        ss >> table[c][r][0];
        while (ss >> word) {
            if (table[c][r][h].length() + word.length() < 10) {
                table[c][r][h] += ' ' + word;
            } else table[c][r][++h] = word;
        }
        height[c][r] = h + 1;
        maxh[c] = max(maxh[c], height[c][r]);
    }
    cout << delimiter;
    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != maxh[i]; ++j) {
            cout << '|';
            for (int k = 0; k != 3; ++k) {
                if (height[i][k]) {
                    cout << table[i][k][j];
                    cout << string(10 - table[i][k][j].length(), ' ');
                } else cout << string(10, ' ');
                cout << '|';
            }
            cout << '\n';
        }
        cout << delimiter;
    }
    return 0;
}
