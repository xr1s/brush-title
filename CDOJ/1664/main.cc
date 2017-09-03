#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char expr[20];
long long Bob;
int len;

long long eval(char expr[], int len) {
    long long M[20] = { 0 }; int Mlen = 0;
    long long sum = 0;
    for (int i = 0; i < len; ++i)
        if (expr[i] == '*')
            M[Mlen - 1] *= (expr[i + 1] - '0'), ++i;
        else if (isdigit(expr[i])) M[Mlen++] = expr[i] - '0';
    for (int i = 0; i != Mlen; ++i) sum += M[i];
    return sum;
}

int main() {
    scanf("%s", expr);
    len = strlen(expr);
    long long M = eval(expr, len);
    long long L = expr[0] - '0';
    for (int i = 1; i < len; i += 2)
        switch (expr[i]) {
            case '+': L += expr[i + 1] - '0'; break;
            case '*': L *= expr[i + 1] - '0'; break;
       }
    scanf("%lld", &Bob);
    if (M == Bob && L == Bob) puts("U");
    else if (M == Bob) puts("M");
    else if (L == Bob) puts("L");
    else puts("I");
    return 0;
}
