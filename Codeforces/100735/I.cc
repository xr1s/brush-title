#include <iostream>
#include <vector>

#ifndef _INTEGER_H_
# define _INTEGER_H_

class integer {
public:
    integer(long long x = 0);
    explicit operator bool();

    friend std::istream &operator>>(std::istream&, integer&);
    friend std::ostream &operator<<(std::ostream&, const integer&);

    friend integer operator-(const integer&);
    friend integer operator+(const integer&);

    friend integer &operator++(integer&);
    friend integer operator++(integer&, int);
    friend integer &operator--(integer&);
    friend integer operator--(integer&, int);

    friend integer operator+(integer, const integer&);
    friend integer operator-(integer, const integer&);
    // TODO: support Fast Fourier Transform
    friend integer operator*(const integer&, const integer&);
    friend integer operator/(const integer&, const integer&);
    friend integer operator/(integer, const int32_t&);
    friend integer operator%(const integer&, const integer&);
    friend integer operator%(const integer&, const int32_t&);

    friend integer &operator+=(integer&, const integer&);
    friend integer &operator-=(integer&, const integer&);
    friend integer &operator*=(integer&, const integer&);
    friend integer &operator/=(integer&, const integer&);
    friend integer &operator/=(integer&, const int32_t&);
    friend integer &operator%=(integer&, const integer&);
    friend integer &operator%=(integer&, const int32_t&);

    friend bool operator==(const integer&, const integer&);
    friend bool operator!=(const integer&, const integer&);
    friend bool operator<(const integer&, const integer&);
    friend bool operator>(const integer&, const integer&);
    friend bool operator<=(const integer&, const integer&);
    friend bool operator>=(const integer&, const integer&);

private:
    constexpr static int32_t base = 1000000000;
    std::vector<int32_t> number; bool negative;

    void trim_prefix_zeros();
};

#endif // _INTEGER_H_

#include <algorithm>

integer::integer(long long value) {
    this->number.clear();
    this->negative = value < 0;
    // in case of value == INTMAX_MIN
    // where value = -value will overflow
    // so save partial to *this->number first
    number.push_back(std::abs(value % integer::base));
    if ((value /= integer::base) < 0) value = -value;
    while (value) {
        this->number.push_back(value % integer::base);
        value /= integer::base;
    }
}

std::istream &operator>>(std::istream &is, integer &rhs) {
    rhs.number.clear();
    rhs.negative = false;
    int next_char = is.peek();
    while (isspace(next_char)) {
        is.get();
        next_char = is.peek();
    }
    // negative or positive
    if (next_char == '-' || next_char == '+') {
        rhs.negative = next_char == '-';
        is.get();
        next_char = is.peek();
    }
    // if non-digital character
    if (!isdigit(next_char)) {
        rhs.number.push_back(0);
        is.clear(std::ios::failbit);
        return is;
    }
    while (next_char == '0') {
        // prefix zeros have no sense
        is.get();
        next_char = is.peek();
    }
    // start reading
    int32_t value = 0, length = 1;
    while (isdigit(is.peek())) {
        next_char = is.get();
        (value *= 10) += next_char - '0';
        if ((length *= 10) == integer::base) {
            rhs.number.push_back(value);
            value = 0; length = 1;
        }
    }
    if (length != 1) {
        rhs.number.push_back(value);
        const int32_t shift = integer::base / length;
        // reverse vector and adjust offset
        for (size_t i = rhs.number.size() - 1; i; --i) {
            rhs.number[i] += rhs.number[i - 1] % shift * length;
            rhs.number[i - 1] /= shift;
        }
    }
    reverse(rhs.number.begin(), rhs.number.end());
    // if all were zero
    if (!rhs.number.size()) {
        rhs.negative = false;
        rhs.number.push_back(0);
    };
    // and f**k negative zero
    return is;
}

std::ostream &operator<<(std::ostream &os, const integer &rhs) {
    if (rhs.negative) os << '-';
    os << rhs.number.back();
    // I am considering not using `auto' here
    for (auto iter = rhs.number.rbegin() + 1; iter != rhs.number.rend(); ++iter) {
        if (*iter < 100000000) os << '0';
        if (*iter < 10000000) os << '0';
        if (*iter < 1000000) os << '0';
        if (*iter < 100000) os << '0';
        if (*iter < 10000) os << '0';
        if (*iter < 1000) os << '0';
        if (*iter < 100) os << '0';
        if (*iter < 10) os << '0';
        os << *iter;
    }
    return os;
}

integer operator+(integer lhs, const integer &rhs) {
    return lhs += rhs;
}

integer &operator+=(integer &lhs, const integer &rhs) {
    if (lhs.negative == rhs.negative) {
        const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
        if (lhs.number.capacity() <= lenr) lhs.number.reserve(lenr + 1);
        if (lenl < lenr) lhs.number.resize(lenr);
        int32_t carry = 0;
        for (size_t i = 0; i != lenr; ++i) {
            carry += lhs.number[i] + rhs.number[i];
            // if-else is much faster than / and %
            if (carry < integer::base) lhs.number[i] = carry;
            else lhs.number[i] = carry - integer::base;
            carry = carry >= integer::base;
            // here carry should always be 0 or 1
        }
        for (size_t i = lenr; carry && i < lenl; ++i)
            if ((carry = ((lhs.number[i] += carry) == integer::base))) lhs.number[i] = 0;
        // 1st: lhs.number[i] += carry
        // 2nd: carry = (lhs.number[i] == integer::base)
        // 3rd: if (carry) lhs.number[i] = 0
        if (carry) lhs.number.push_back(1);
    } else lhs.negative ^= 1, lhs -= rhs, lhs.negative ^= 1;
    if (lhs.number.size() == 1 && !lhs.number.front()) lhs.negative = false;
    return lhs;
}

integer operator-(integer lhs, const integer &rhs) {
    return lhs -= rhs;
}

integer &operator-=(integer &lhs, const integer &rhs) {
    if (lhs.negative == rhs.negative) {
        const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
        if (lenl < lenr) lhs.number.resize(lenr);
        bool carry = false;
        if ((lhs > rhs) ^ lhs.negative) {  // if abs(lhs) > abs(rhs)
            for (size_t i = 0; i != lenr; ++i) {
                lhs.number[i] -= rhs.number[i] + carry;
                if ((carry = lhs.number[i] < 0))
                    lhs.number[i] += integer::base;
            }
            for (size_t i = lenr; carry && i < lenl; ++i)
                if ((carry = !~--lhs.number[i])) lhs.number[i] = integer::base - 1;
            // 1st: --lhs.number[i]
            // 2nd: carry = lhs.number[i] == -1
            // 3rd: if (carry) lhs.number[i] = integer::base - 1
        } else {  // if (abs(lhs) < abs(rhs)), use lhs - rhs = -(rhs - lhs)
            lhs.negative ^= 1;
            for (size_t i = 0; i != lenr; ++i) {
                lhs.number[i] = rhs.number[i] - lhs.number[i] - carry;
                if ((carry = lhs.number[i] < 0)) lhs.number[i] += integer::base;
            }
        }
    } else lhs.negative ^= 1, lhs += rhs, lhs.negative ^= 1;
    lhs.trim_prefix_zeros();
    return lhs;
}

bool operator==(const integer &lhs, const integer &y) {
    return lhs.negative == y.negative && lhs.number == y.number;
}

bool operator!=(const integer &lhs, const integer &rhs) {
    return lhs.negative != rhs.negative || lhs.number != rhs.number;
}

bool operator<(const integer &lhs, const integer &rhs) {
    if (lhs.negative ^ rhs.negative) return lhs.negative;
    const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
    if (lenl != lenr) return (lenl < lenr) ^ lhs.negative;
    for (size_t i = lenl - 1; i; --i)
        if (lhs.number[i] != rhs.number[i])
            return (lhs.number[i] < rhs.number[i]) ^ lhs.negative;
    return (lhs.number.front() < rhs.number.front()) ^ rhs.negative;
}

bool operator>(const integer &lhs, const integer &rhs) {
    if (lhs.negative ^ rhs.negative) return rhs.negative;
    const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
    if (lenl != lenr) return (lenl > lenr) ^ rhs.negative;
    for (size_t i = lenr - 1; i; --i)
        if (lhs.number[i] != rhs.number[i])
            return
                    (lhs.number[i] > rhs.number[i]) ^ rhs.negative;
    return (lhs.number.front() > rhs.number.front()) ^ rhs.negative;
}

bool operator<=(const integer &lhs, const integer &rhs) {
    if (lhs.negative ^ rhs.negative) return lhs.negative;
    const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
    if (lenl != lenr) return (lenl < lenr) ^ lhs.negative;
    for (int i = lenl - 1; i; --i)
        if (lhs.number[i] != rhs.number[i])
            return (lhs.number[i] < rhs.number[i]) ^ lhs.negative;
    return lhs.number.front() == rhs.number.front()
           || (lhs.number.front() < rhs.number.front()) ^ lhs.negative;
}

bool operator>=(const integer &lhs, const integer &rhs) {
    if (lhs.negative ^ rhs.negative) return rhs.negative;
    const size_t lenl = lhs.number.size(), lenr = rhs.number.size();
    if (lenl != lenr) return (lenl > lenr) ^ rhs.negative;
    for (int i = lenr - 1; i; --i)
        if (lhs.number[i] != rhs.number[i])
            return (lhs.number[i] > rhs.number[i]) ^ rhs.negative;
    return lhs.number.front() == rhs.number.front()
           || (lhs.number.front() > rhs.number.front()) ^ rhs.negative;
}

integer::operator bool() {
    return this->negative || this->number.size() != 1 || this->number.front();
}

void integer::trim_prefix_zeros() {
    size_t length = this->number.size() - 1;
    while (!this->number[length] && length) --length;
    this->number.resize(length + 1);
    // Take care of negative zero
    if (!length && !this->number.back()) this->negative = false;
}

using namespace std;

integer a, b, c;

int main() {
    cin >> a >> b >> c;
    if (a == 0 || b == 0 || c == 0) {
        puts("YES");
        return 0;
    }
    if (a + a == b || a + a == c || b + b == a || b + b == c || c + c == a || c + c == b || a + b == c || a + c == b || b + c == a) {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}
