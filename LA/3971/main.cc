#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int T, n, b, price, quality;
string type, name;
unordered_map<string, vector<pair<int, int>>> comp;

bool afford(int quality, int limit) {
    int total = 0;
    for (auto &type: comp) {
        vector<pair<int, int>> &list = type.second;
        int price = 1000000;
        for (auto &comp: list)
            if (comp.second >= quality)
                price = min(price, comp.first);
        total += price;
        if (total > limit) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (cin >> T; T; --T) {
        comp.clear();
        cin >> n >> b;
        for (int i = 0; i != n; ++i) {
            cin >> type >> name >> price >> quality;
            comp[type].emplace_back(price, quality);
        }
        int bound[2] = {0, 1000000001};
        while (bound[0] + 1 != bound[1]) {
            int m = bound[0] + bound[1] >> 1;
            bound[!afford(m, b)] = m;
        }
        cout << *bound << '\n';
    }
    return 0;
}
