#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int n; double W;
char tmp[10];

int main() {
    scanf("%d%lf", &n, &W);
    int safe = 0;
    double ans = 0, curp = 1, current = 0;
    while (n--) {
        double p; int v;
        scanf("%s%lf%d", tmp, &p, &v);
        double success = curp * p * log(1 + v / W);
        double fail = curp * (1 - p) * log(1 + safe / W);
        ans = max(ans, current + success + fail);
        current += fail; curp *= p;
        if (!strcmp(tmp, "safe")) safe = v;
    }
    printf("$%.2f\n", W * exp(ans) - W);
    return 0;
}
