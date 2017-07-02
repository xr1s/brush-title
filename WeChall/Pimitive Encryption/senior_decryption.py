from os.path import getsize
from sys import stderr


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


def progress_bar(percentage):
    reminder = (' ', '▏', '▎', '▍', '▌', '▋', '▊', '▉')
    stderr.write('\r' + ' ' * 80 + '\r ')
    stderr.flush()
    stderr.write('▉' * int(70 * percentage))
    stderr.write(reminder[int(560 * percentage) & 7])
    stderr.write(' {:5.2f}%'.format(percentage * 100))
    stderr.flush()


if __name__ == '__main__':
    modified = open('pimitive.zip', 'rb')
    size = getsize('pimitive.zip')
    original = open('original.zip', 'wb')
    pi = pi_digit()

    original.write(bytes([ord(modified.read(1)) ^ next(pi) + ord('0')]))
    original.write(bytes([ord(modified.read(1)) ^ ord('.')]))
    for k, c in enumerate(modified.read()):
        progress_bar(k / size)
        original.write(bytes([c ^ next(pi) + ord('0')]))
    print()
    modified.close()
    original.close()
