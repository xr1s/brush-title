#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, array[15];

void operate(int array[]) {
    int diff = array[N - 1] - array[0];
    array[0] = array[N - 1] = diff;
    sort(array, array + N);
}

bool check(int array[]) {
    return array[0] == array[N - 1];
}

int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &N);
        for (int i = 0 ; i != N; ++i)
            scanf("%d", &array[i]);
        sort(array, array + N);
        bool flag = false;
        for (int i = 0; i != 233333; ++i)
            if (check(array)) {
                printf("%d\n", array[0]);
                flag = true;
                break;
            } else operate(array);
        if (!flag) puts("Nooooooo!");
    }
    return 0;
}
