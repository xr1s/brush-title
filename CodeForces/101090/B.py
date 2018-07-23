from decimal import *

n, k = map(int, input().split())
getcontext().prec = k + 10
print(str(round(Decimal(n).sqrt(), k + 5))[:-5])
