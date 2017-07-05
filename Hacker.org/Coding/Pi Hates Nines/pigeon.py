from os.path import getsize


def pi_digit():
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

if __name__ == '__main__':
    longest = []
    new = []
    pi = pi_digit()
    for i in range(1000000):
        digit = next(pi)
        if digit != 9:
            new.append(digit)
        elif len(new) > len(longest):
            longest = new
            print(''.join(map(str, longest)), flush=True)
            new = []
        else:
            new = []
    print('finished')

