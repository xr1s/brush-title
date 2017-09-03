#include <cstdio>
#include <cstring>

using namespace std;

enum operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
} op[15];

int n;
char ops[10];
int opn[15];
int answer;

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%s%d", ops, &opn[i]);
        if (!strcmp(ops, "ADD"))        op[i] = ADD;
        if (!strcmp(ops, "SUBTRACT"))   op[i] = SUBTRACT;
        if (!strcmp(ops, "MULTIPLY"))   op[i] = MULTIPLY;
        if (!strcmp(ops, "DIVIDE"))     op[i] = DIVIDE;
    }
    for (int i = 1; i <= 100; ++i) {
        int number = i, flag = false;
        for (int j = 0; j != n; ++j) {
            switch (op[j]) {
                case ADD:
                    number += opn[j];
                    break;
                case SUBTRACT:
                    number -= opn[j];
                    if (number < 0) flag = true;
                    break;
                case MULTIPLY:
                    number *= opn[j];
                    break;
                case DIVIDE:
                    if (number / opn[j] * opn[j] != number) flag = true;
                    number /= opn[j];
                    break;
            }
        }
        if (flag) ++answer;
    }
    printf("%d\n", answer);
    return 0;
}
