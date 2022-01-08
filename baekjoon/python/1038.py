from sys import stdin
from math import factorial
def cmb(a, b):
    if a == b:
        return 1
    return factorial(a) // factorial(b) // factorial(a - b)
def down(n, l):
    global rst
    if l < 0:
        return
    sum = 0
    k = l
    while sum + cmb(k, l) <= n and k <= 9:
        sum += cmb(k, l)
        k += 1
    rst += (10 ** l) * k
    down(n - sum, l - 1)
rst = 0
n = int(stdin.readline())
if n <= 10:
    print(n)
elif n >= 1023:
    print(-1)
else:
    sum = 0
    i = 1
    while sum + cmb(10, i) <= n and i <= 9:
        sum += cmb(10, i)
        i += 1
    down(n - sum, i - 1)
    print(rst)
