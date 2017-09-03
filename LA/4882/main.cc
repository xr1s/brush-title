#include <iostream>
using namespace std;

enum operation {
    ADD, MUL,
};

string simplify(string::iterator st, string::iterator ed, operation op) {
    string result;
    size_t bracket = 0;
    bool add_in_mul = false;
    for (auto r = st + 1, l = r; r + 1 != ed; ++r) {
        if (*r != '(' && *r != ')') {
            add_in_mul |= bracket == 0 && op == MUL && *r == '+';
            if (bracket == 0) result += *r;
        } else if (*r == '(') {
            if (bracket++ == 0) l = r;
        } else if (*r == ')') {
            if (--bracket == 0) {
                if (l == st + 1 && r == ed - 2)
                    result += simplify(l, r + 1, op);
                else if (l != st + 1 && isalpha(l[-1]) != 0)
                    result += simplify(l, r + 1, MUL);
                else if (l != st + 1 && l[-1] == ')')
                    result += simplify(l, r + 1, MUL);
                else if (r != ed - 2 && isalpha(r[1]) != 0)
                    result += simplify(l, r + 1, MUL);
                else if (r != ed - 2 && r[1] == '(')
                    result += simplify(l, r + 1, MUL);
                else result += simplify(l, r + 1, ADD);
            }
        }
    }
    if (add_in_mul) return '(' + result + ')';
    return result;
}

int main() {
    string expr;
    while (cin >> expr) {
        expr = '(' + expr + ')';
        cout << simplify(expr.begin(), expr.end(), ADD) << endl;
    }
    return 0;
}
