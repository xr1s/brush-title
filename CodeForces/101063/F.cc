#include <cstdio>
using namespace std;

int N, K;

int main() {
    scanf("%d%d", &N, &K);
    puts((N + 1) % K ? "no" : "yes");
    return 0;
}

