def isprime(n):
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


# Calculates Euler's phi value
def getphi(n):
    if n == 1:
        return 1
    elif isprime(n):
        return n-1
    prime, phi = 2, n
    while prime*prime <= n:
        if n % prime == 0:
            phi = phi*(prime-1)//prime
        while n % prime == 0:
            n //= prime
        prime += 1
    if n != 1:
        phi = phi*(n-1)//n
    return phi
