def fibonacci():
    fib = [1, 0]
    side = 0
    while True:
        yield fib[side]
        fib[side ^ 1] += fib[side]
        side ^= 1

fibonacci = fibonacci()
for i in range(1, 1500000): next(fibonacci)
fibonacci = str(next(fibonacci))
fibonacci = filter(lambda k: k[0] % 20000 == 0, enumerate(fibonacci))
solution = ''
for k, v in fibonacci:
    solution += v
print(solution)

