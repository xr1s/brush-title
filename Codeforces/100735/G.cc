#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[100005];
int zero, one;

int main() {
    scanf("%s", A);
    int len = strlen(A);
    for (size_t i = 0; i != len; ++i)
        if (A[i] == '0') ++zero; else ++one;
    printf("%d\n", min(zero, one));
    return 0;
}
