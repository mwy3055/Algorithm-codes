from sys import stdin
from math import *
def solve(d):
    i = 1
    while i * i <= d:
        i += 1
    i -= 1
    diff =  (d - i * i) / i
    return 2 * i - 1 + ceil(diff)

t = int(stdin.readline())
for i in range(t):
    x, y = map(int, stdin.readline().rsplit())
    print(solve(y - x))
