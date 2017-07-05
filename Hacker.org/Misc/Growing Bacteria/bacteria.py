'''
#include <iostream>

int main() {
    int num[100][4] = {{1, 0, 0, 0}};
    for (int i = 1; i != 10; ++i) {
        num[i][3] = num[i - 1][2];
        num[i][2] = num[i - 1][1];
        num[i][1] = num[i - 1][0];
        num[i][0] = num[i - 1][0] + num[i - 1][1];
        int total = 0;
        for (int j = 0; j != 4; ++j)
            total += num[i][j];
        std::cout << total << '\n';
    }
    return 0;
}
'''

num = [[0] * 5 for i in range(100)]
num[1][0] = 1

for i in range(2, 100):
    num[i][3] = num[i - 1][2]
    num[i][2] = num[i - 1][1]
    num[i][1] = num[i - 1][0]
    num[i][0] = num[i - 1][0] + num[i - 1][1]
    print(i) if sum(num[i]) > 1_000_000_000_000 else None
