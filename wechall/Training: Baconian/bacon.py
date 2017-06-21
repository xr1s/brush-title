#!/usr/bin/env python3

cipher = input()
for c in range(128):
    if not chr(c).isalpha():
        cipher = cipher.replace(chr(c), '')
print(cipher)

message = ''

for i in range(0, len(cipher) // 5 * 5, 5):
    asc = 0
    for j in range(5):
        if cipher[i + j].isupper():
            asc += 1 << 4 - j
    message += chr(asc + ord('a'))

print(message)

print(' '.join(message.split('x')))

