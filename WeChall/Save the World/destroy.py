from operator import mul
from functools import reduce
from message import n, c


def exgcd(m, n):
    x, y, x1, y1 = 0, 1, 1, 0
    while m % n:
        x, x1 = x1 - m // n * x, x
        y, y1 = y1 - m // n * y, y
        m, n = n, m % n
    return n, x, y


def prod(lst):
    return reduce(mul, lst)


def china_remainder(a, m):
    p = prod(m)
    r = tuple(p // mi for mi in m)
    t = (exgcd(ri, mi)[1] for ri, mi in zip(r, m))
    return sum(ai * ti * ri % p for ai, ti, ri in zip(a, t, r)) % p


def China_remainder(a, m):
    p = prod(m)
    M = list(p // n for n in m)
    t = list(exgcd(M[i], m[i])[1] for i in range(len(m)))
    return sum(a[i] * t[i] * M[i] for i in range(len(m))) % p


def root(p, n):
    l, r = 0, p
    while l + 1 < r:
        m = l + r >> 1
        pm = m ** n
        if pm == p: return m
        elif pm < p: l = m
        elif pm > p: r = m
    if r ** n == p: return r
    else: return None


if __name__ == '__main__':
    m3 = china_remainder(c, n)
    print(str(root(m3, 3))[-20:])
