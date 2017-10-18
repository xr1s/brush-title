#ifndef ELLIPTIC_CURVE
#define ELLIPTIC_CURVE 1

#include <iostream>
#include <random>
#include <gmpxx.h>
//#include "quadratic_reside.hh"

// forward declaration
class elliptic_curve;
class elliptic_point;

/**
 * Descrete Elliptic Curve abstract class.
 * Described as y² ≡ x³ + ax + b (mod p).
 */
class elliptic_curve {
  public:
    using point = elliptic_point;
    using curve = elliptic_curve;
    friend elliptic_point;
    friend point operator-(const point &);
    friend point operator+(const point &, const point &);

    template <typename a_mpz, typename b_mpz, typename p_mpz>
    elliptic_curve(a_mpz &&, b_mpz &&, p_mpz &&);
    elliptic_curve(const curve &) = default;
    elliptic_curve(curve &&) = delete;
    template <typename x_mpz, typename y_mpz>
    elliptic_point at(x_mpz &&, y_mpz &&);
    elliptic_point randpoint();

    friend bool operator==(const curve &, const curve &);
    friend bool operator!=(const curve &, const curve &);

  private:
    mpz_class a, b, p;
};

/**
 * A point on the curve.
 * Caution, the point cannot live without curve.
 * So once the curve is recycled, the point is invalid.
 */
class elliptic_point {
  public:
    friend elliptic_curve;
    using curve = elliptic_curve;
    using point = elliptic_point;

    mpz_class x, y;
    elliptic_point(const point &) = default;
    elliptic_point(point &&) = default;
    point &operator=(const point &);

    // Group arithemetics
    friend bool operator==(const point &, const point &);
    friend bool operator!=(const point &, const point &);
    friend point operator+(const point &);
    friend point operator-(const point &);
    friend point operator+(const point &, const point &);
    friend point &operator+=(point &, const point &);
    friend point operator-(const point &, const point &);
    friend point &operator-=(point &, const point &);
    template <typename mpz> friend point operator*(point, mpz &&);
    template <typename mpz> friend point operator*(mpz &&, point);

    friend std::ostream &operator<<(std::ostream &, const point &);

  private:
    using mpz = mpz_class;

    const curve *on;
    bool identity;

    template <typename x_mpz, typename y_mpz>
    elliptic_point(const curve *, x_mpz &&, y_mpz &&);
    explicit elliptic_point(const curve *);
};

/**
 * y² ≡ x³ + ax + b (mod p).
 * Can be constructed from any type that constructs mpz_class.
 */
template <typename a_mpz, typename b_mpz, typename p_mpz>
elliptic_curve::elliptic_curve(a_mpz &&at, b_mpz &&bt, p_mpz &&pt) {
    mpz_class p{std::forward<p_mpz>(pt)};
    mpz_class a{std::forward<a_mpz>(at)};
    mpz_class b{std::forward<b_mpz>(bt)};
    if ((4 * a * a * a + 27 * b * b) % p == 0)
        throw std::invalid_argument("The curve is not valid for encryption.");
    this->p = std::move(p);
    this->a = std::move(a);
    this->b = std::move(b);
}

/**
 * The point can only be constructed through invoking elliptic curve member
 * function `at'.
 * Will throw `std::invalid_argument' if the coordinate is not on the curve;
 */
template <typename x_mpz, typename y_mpz>
elliptic_point elliptic_curve::at(x_mpz &&xt, y_mpz &&yt) {
    mpz_class x{std::forward<x_mpz>(xt)};
    mpz_class y{std::forward<y_mpz>(yt)};
    if ((y * y - x * x * x - this->a * x - this-> b) % this->p != 0)
        throw std::invalid_argument("The coordinate is not on the curve.");
    return elliptic_point{this, x, y};
}

/*
elliptic_point elliptic_curve::randpoint() {
    static std::random_device rd;
    static mpz_class seed = rd();
    static gmp_randstate_t gen;
    static bool init = false;
    if (!init) {
        gmp_randinit_mt(gen);
        gmp_randseed(gen, seed.get_mpz_t());
        init = true;
    }
    mpz_class x, y;
    do {
        mpz_urandomm(x.get_mpz_t(), gen, p.get_mpz_t());
        y = sqrt(x * x * x + a * x + b, p);
    } while (y == -1);
    return this->at(x, y);
}
*/

/**
 * Only construct the identity element of elliptic curve group.
 * This ctor is private and will only be invoked by operator+.
 */
elliptic_point::elliptic_point(const elliptic_curve *ec) {
    this->identity = true;
    this->on = ec;
}

/**
 * Check if two curves is coincident.
 */
bool operator==(const elliptic_curve &lhs, const elliptic_curve &rhs) {
    return lhs.p == rhs.p && lhs.a == rhs.a && lhs.b == rhs.b;
}

bool operator!=(const elliptic_curve &lhs, const elliptic_curve &rhs) {
    return lhs.p != rhs.p || lhs.a != rhs.a || lhs.b != rhs.b;
}

/**
 * Construct a point on elliptic curve.
 * This ctor is private and can only be invoked by elliptic_curve::at,
 * which will validate the coordinate so here is no need to check again.
 */
template <typename x_mpz, typename y_mpz>
elliptic_point::elliptic_point(const elliptic_curve *ec, x_mpz &&x, y_mpz &&y) {
    this->identity = false;
    this->on = ec;
    this->x = std::forward<x_mpz>(x);
    this->y = std::forward<y_mpz>(y);
}

elliptic_point &elliptic_point::operator=(const elliptic_point &rhs) {
    this->identity = rhs.identity;
    this->on = rhs.on;
    this->x = rhs.x;
    this->y = rhs.y;
}

/**
 * Check if two points is coincident.
 */
bool operator==(const elliptic_point &lhs, const elliptic_point &rhs) {
    return lhs.identity == rhs.identity
           && lhs.x == rhs.x
           && lhs.y == rhs.y
           && *lhs.on == *rhs.on;
}

bool operator!=(const elliptic_point &lhs, const elliptic_point &rhs) {
    return lhs.identity != rhs.identity
           || lhs.x != rhs.x
           || lhs.y != rhs.y
           || *lhs.on != *rhs.on;
}

/**
 * @return Self.
 */
elliptic_point operator+(const elliptic_point &ep) {
    return elliptic_point{ep.on, ep.x, ep.y};
}

/**
 * @return Group theory inverse.
 */
elliptic_point operator-(const elliptic_point &ep) {
    return elliptic_point{ep.on, ep.x, ep.on->p - ep.y};
}

/**
 * Add operator in elliptic curve group.
 * See https://en.wikipedia.org/wiki/Elliptic_curve for details.
 */
elliptic_point operator+(const elliptic_point &lhs, const elliptic_point &rhs) {
    if (*lhs.on != *rhs.on)
        throw std::invalid_argument("Not in the same curve.");
    if (lhs.identity) return rhs;
    if (rhs.identity) return lhs;
    if (lhs == -rhs) return elliptic_point(lhs.on);
    const mpz_class &p = lhs.on->p, &a = lhs.on->a;
    mpz_class s;
    if (lhs == rhs) {
        const mpz_class t = 2 * lhs.y;
        mpz_invert(s.get_mpz_t(), t.get_mpz_t(), p.get_mpz_t());
        (s *= 3 * lhs.x * lhs.x + a) %= p;
    } else {
        const mpz_class dx = lhs.x - rhs.x;
        mpz_invert(s.get_mpz_t(), dx.get_mpz_t(), p.get_mpz_t());
        (s *= lhs.y - rhs.y) %= p; if (s < 0) s += p;
    }
    mpz_class &&x = (s * s - lhs.x - rhs.x) % p;
    mpz_class &&y = (s * (lhs.x - x) - lhs.y) % p;
    if (x < 0) x += p; if (y < 0) y += p;
    return elliptic_point(lhs.on, x, y);
}

elliptic_point &operator+=(elliptic_point &lhs, const elliptic_point &rhs) {
    return lhs = lhs + rhs;
}

elliptic_point operator-(const elliptic_point &lhs, const elliptic_point &rhs) {
    return lhs + -rhs;
}

elliptic_point &operator-=(elliptic_point &lhs, const elliptic_point &rhs) {
    return lhs = lhs + -rhs;
}

/**
 * point * scalar = sum of scalar number of points
 */
template <typename mpz>
elliptic_point operator*(elliptic_point lhs, mpz &&scalar) {
    mpz_class rhs{std::forward<mpz>(scalar)};
    elliptic_point res{lhs.on};
    do {
        if ((rhs & 1) != 0) res += lhs;
        if (rhs != 1) lhs += lhs;
    } while (rhs >>= 1);
    return res;
}

template <typename mpz>
elliptic_point operator*(mpz &&scalar, elliptic_point rhs) {
    mpz_class lhs{std::forward<mpz>(scalar)};
    elliptic_point res{rhs.on};
    do {
        if ((lhs & 1) != 0) res += rhs;
        if (lhs != 1) rhs += rhs;
    } while (lhs >>= 1);
    return res;
}

std::ostream &operator<<(std::ostream &os, const elliptic_point &ep) {
    if (ep.identity) os << "(inf, inf)";
    else os << '(' << ep.x << ", " << ep.y << ')';
}

#endif  //  ELLIPTIC_CURVE
