#include <cstdio>
using namespace std;

int T, n, m;

template <typename integer>
integer gcd(integer m, integer n) {
    integer r;
    while (r = m % n) m = n, n = r;
    return n;
}

template <typename integer>
integer lcm(integer m, integer n) {
    integer g = gcd(m, n);
    return m / g * n;
}

typedef long long integer;

//template <typename integer>
struct fraction {
    integer numerator, denominator;
    fraction() : numerator(0), denominator(1) {}
    fraction(const integer &i) : numerator(i), denominator(1) {}
    fraction(const integer &, const integer &);
    friend fraction operator+(const fraction &, const fraction &);
    friend fraction &operator+=(fraction &, const fraction &);
    friend fraction operator*(const fraction &, const fraction &);
    friend fraction &operator*=(fraction &, const fraction &);
};

//template <typename integer>
fraction::fraction(const integer &numerator, const integer &denumerator) {
    integer g = gcd(numerator, denumerator);
    this->numerator = numerator / g;
    this->denominator = denumerator / g;
}

//template <typename integer>
fraction operator+(const fraction &lhs, const fraction &rhs) {
    integer g = gcd(lhs.denominator, rhs.denominator);
    integer denominator = lcm(lhs.denominator, rhs.denominator);
    integer numerator = 0;
    numerator += lhs.numerator * (rhs.denominator / g);
    numerator += rhs.numerator * (lhs.denominator / g);
    return fraction(numerator, denominator);
}

//template <typename integer>
fraction &operator+=(fraction &lhs, const fraction &rhs) {
    return lhs = lhs + rhs;
}

//template <typename integer>
fraction operator*(const fraction &lhs, const fraction &rhs) {
    integer g0 = gcd(lhs.numerator, rhs.denominator);
    integer g1 = gcd(rhs.numerator, lhs.denominator);
    integer numerator = (lhs.numerator / g0) * (rhs.numerator / g1);
    integer denominator = (lhs.denominator / g1) * (rhs.denominator / g0);
    return fraction(numerator, denominator);
}

//template <typename integer>
fraction &operator*=(fraction &lhs, const fraction &rhs) {
    return lhs = lhs * rhs;
}

void print(const fraction &s) {
    printf("%lld/%lld", s.numerator, s.denominator);
}


int main() {
    for (scanf("%d", &T); T; --T) {
        scanf("%d%d", &n, &m);
        fraction sum = 0;
        for (int i = 0; i < m + n; i += 2) {
            fraction s = 1;
            for (int j = 0; j != i; ++j)
                s *= fraction(m - j, m + n - j);
            sum += s * fraction(n, m + n - i);
        }
        print(sum);
        putchar('\n');
    }
    return 0;
}
