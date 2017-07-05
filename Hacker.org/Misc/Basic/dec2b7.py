number = int(input())
base7 = []
while number:
    base7.append(str(number % 7))
    number //= 7
print(''.join(reversed(base7)))
