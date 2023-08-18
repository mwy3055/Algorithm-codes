import math


def isprime(n):
    for i in range(2, n):
        if i*i > n:
            break
        if n % i == 0:
            return False
    return True


def getphi(n):
    if isprime(n):
        return n-1
    phi = n
    for p in range(2, n):
        if p*p > n:
            break
        if n % p == 0:
            phi *= p-1
            phi //= p
            while n % p == 0:
                n //= p
    if n > 1:
        phi *= n-1
        phi /= n
    return phi


def getpow(a, x, n):
    if x == 0:
        return 1
    elif x == 1:
        return a
    half = getpow(a, x//2, n)
    result = ((half % n)*(half % n)) % n
    if x % 2 == 1:
        result = (result*a) % n
    return result


n, a = map(int, input().split())
inv_sum = n-a
if math.gcd(a, n) != 1:
    inv_mul = -1
else:
    varphi = getphi(n)
    inv_mul = getpow(a, varphi-1, n)
print(f'{inv_sum} {inv_mul}')
