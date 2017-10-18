#!/usr/bin/env python3


def exgcd(m, n):
    x, y, x1, y1 = 0, 1, 1, 0
    while m % n:
        x, x1 = x1 - m // n * x, x
        y, y1 = y1 - m // n * y, y
        m, n = n, m % n
    return n, x, y


def modinv(m, n):
    gcd, inv = exgcd(m, n)[:2]
    return inv % (n // gcd)


if __name__ == '__main__':
    p = 275127860351348928173285174381581152299
    q = 319576316814478949870590164193048041239
    e = 0x10001
    n = p * q
    r = (p - 1) * (q - 1)
    d = modinv(e, r)
    with open('flag.enc', 'rb') as flag:
        enc = int.from_bytes(flag.read(), 'big')
    msg = pow(enc, d, n)
    msg = msg.to_bytes(31, 'big')
    print(msg)
