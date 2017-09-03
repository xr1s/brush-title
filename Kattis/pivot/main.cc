#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int arr[100005];
int mini[100005], maxi[100005];
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) scanf("%d", &arr[i]);
    maxi[0] = arr[0]; mini[n - 1] = arr[n - 1];
    for (int i = 1; i != n; ++i)
        maxi[i] = max(maxi[i - 1], arr[i]);
    for (int i = n - 2; ~i; --i)
        mini[i] = min(mini[i + 1], arr[i]);
    for (int i = 1; i != n - 1; ++i)
        if (maxi[i - 1] < arr[i] && arr[i] < mini[i + 1]) ++ans;
    if (arr[0] == mini[0]) ++ans;
    if (arr[n - 1] == maxi[n - 1]) ++ans;
    printf("%d\n", ans);
    return 0;
}
