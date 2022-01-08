MOD = 1000000007


def power(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = (ans*x) % MOD
        x = (x*x) % MOD
        y //= 2
    return ans


def fac(n):
    ans = 1
    for i in range(2, n+1):
        ans = (ans*i) % MOD
    return ans


n, k = map(int, input().split())
if n == k or k == 0:
    print(1)
    exit(0)
a, b, c = fac(n), fac(k), fac(n-k)
print((a*power(b*c, MOD-2)) % MOD)
