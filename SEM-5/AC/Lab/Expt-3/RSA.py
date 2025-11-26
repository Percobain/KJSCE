import math
from sympy import math_inverse, factorint, isprime

p = 61
q = 53
n = p * q
phi = (p - 1)*(q - 1)
e = 17
d = mod_inverse(e, phi)

print(f"Public Key (n, e): ({n}, {e})")
print(f"Private Key (n, d): ({n}, {d})")

M = 23
print(f"Original Message M = {M}")

sign = pow(M, d, n)
print(f"Signature (M^d mod n) = {sign}")

rec = pow(sign, e, n)
print(f"Recovered message (signature^e mod n) = {rec}")