#include <cstdio>
#include <algorithm>

using namespace std;

int m, n;
int customer[15];
int trash[15];

int main() {
    while (~scanf("%d%d", &m, &n) && (m || n)) {
        int cut = 0;
        for (int i = 0; i != m; ++i) scanf("%d", &customer[i]);
        for (int j = 0; j != n; ++j) {
            bool match = true;
            for (int i = 0; i != m; ++i) scanf("%d", &trash[i]);
            for (int i = 0; i != m && match; ++i)
                if (trash[i] > customer[i]) match = false;
            cut += match;
        }
        printf("%d\n", cut);
    }
    return 0;
}
