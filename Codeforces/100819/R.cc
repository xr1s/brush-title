#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
pair<string, string> name[105];

int main() {
    cin >> n;
    for (int i = 0; i != n; ++i)
        cin >> name[i].second >> name[i].first;
    sort(name, name + n);
    for (int i = 0; i != n; ++i)
        cout << name[i].second << ' ' << name[i].first << '\n';
    return 0;
}
