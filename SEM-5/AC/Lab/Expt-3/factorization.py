import math
from sympy import mod_inverse

n = 3233
e = 17
sign = 765

def factor_trial(n):
    if n % 2 == 0:
        return 2, n // 2
    limit = int(math.isqrt(n)) + 1
    for i in range(3, limit, 2):
        if n % i == 0:
            return i, n // i
    return None, None

p, q = factor_trial(n)
print(f"Factors found: p = {p}, q = {q}")

phi = (p - 1) * (q - 1)
print(f"Computed phi(n) = {phi}")

d = mod_inverse(e, phi)
print(f"Computed private key d = {d}")

rec = pow(sign, e, n)
print(f"Recovered message from signature^d mod n = {rec}")
