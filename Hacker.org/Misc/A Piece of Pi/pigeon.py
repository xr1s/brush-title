def pigeon():
    q, r, t, k, m, x = 1, 0, 1, 1, 3, 3
    while True:
        if q << 2 < m * t + t - r:
            yield m
            q = 10 * q
            r = 10 * (r - m * t)
            m = (3 * q + r) // t
        else:
            t = t * x
            m = (q * (7 * k + 2) + r * x) // t
            r = (2 * q + r) * x
            q = k * q
            k = k + 1
            x = x + 2

pi = pigeon()
number = next(pi)
count = 0
print(count, number)
for pid in pi:
    number *= 10
    number += pid
    number %= 1000000000
    count += 1
    print(count, number)
    if number == 12345678:
        break
print(count)
