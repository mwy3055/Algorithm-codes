MOD = int(1e9+7)


def exp(n, x):
    if x <= 1:
        return n**x
    half = exp(n, x//2)
    full = (half*half) % MOD
    if x % 2 == 1:
        full = (full*n) % MOD
    return full


for _ in range(int(input())):
    n = int(input())
    if n <= 2:
        print(1)
    else:
        print(exp(2, n-2))
