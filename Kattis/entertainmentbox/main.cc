#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

int n, k, answer;
pair<int, int> show[100005];
multiset<int> tape;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i != n; ++i)
        scanf("%d%d", &show[i].second, &show[i].first);
    sort(show, show + n);
    for (int i = 0; i != k; ++i) tape.insert(0);
    for (int i = 0; i != n; ++i) {
        auto p = tape.upper_bound(show[i].second);
        if (p == tape.begin()) continue;
        tape.erase(--p); tape.insert(show[i].first);
        ++answer;
    }
    printf("%d\n", answer);
    return 0;
}
