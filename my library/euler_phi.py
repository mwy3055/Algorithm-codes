def isprime(n):
    for i in range(2, n):
        if i*i > n:
            break
        if n % i == 0:
            return False
    return True


# Calculates Euler's phi value
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
