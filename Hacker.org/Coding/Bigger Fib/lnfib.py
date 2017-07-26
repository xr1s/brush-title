from math import sqrt, log
from decimal import *

getcontext().prec = 12
phi = Decimal(5).sqrt() / 2 + Decimal(.5)

print(150000000 * phi.ln() - Decimal(5).sqrt().ln())

