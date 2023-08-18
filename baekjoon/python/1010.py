from sys import stdin
def fac(n):
    rtn = 1
    for i in range(1, n + 1):
        rtn *= i
    return rtn

t = int(stdin.readline())
for i in range(t):
    n, k = map(int, stdin.readline().rsplit())
    print(fac(k) // fac(n) // fac(k - n))
