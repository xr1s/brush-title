//#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct fraction {
    int numerator, denominator;
};

/*
ostream &operator<<(ostream &os, const fraction &f) {
    cout << f.numerator << '/' << f.denominator;
}
*/

int T, n;

void generator(int n, fraction lhs, fraction rhs, vector<fraction> &seq) {
    int numerator = lhs.numerator + rhs.numerator;
    int denominator = lhs.denominator + rhs.denominator;
    if (denominator > n) return;
    fraction mid = {numerator, denominator};
    generator(n, lhs, mid, seq);
    seq.push_back(mid);
    generator(n, mid, rhs, seq);
}

vector<fraction> farey(int n) {
    constexpr fraction st = {0, 1};
    constexpr fraction ed = {1, 1};
    vector<fraction> seq;
    generator(n, st, ed, seq);
    return seq;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &n);
        auto v = farey(n);
        auto last = *v.rbegin();
        v.pop_back();
        for (auto &f: v)
            printf("%d/%d,", f.numerator, f.denominator);
        printf("%d/%d\n", last.numerator, last.denominator);
    }
    return 0;
}
