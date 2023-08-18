import sys
import math
from collections import deque
input = sys.stdin.readline


def preprocess():
    temp = [False for _ in range(2000010)]
    INF = 2000001
    temp[0] = temp[1] = True
    i = 2
    while i*i < INF:
        if not temp[i]:
            j = i*i
            while j < INF:
                temp[j] = True
                j += i
        i += 1
    for i, t in enumerate(temp):
        if not t:
            primes.append(i)


def isprime(n):
    for prime in primes:
        if prime*prime > n:
            break
        if n % prime == 0:
            return False
    return True


primes = deque()
preprocess()
for _ in range(int(input().strip())):
    a, b = map(int, input().strip().split())
    n = a+b
    if n <= 3:
        print('NO')
    elif n % 2 == 0:
        print('YES')
    else:
        print('YES' if isprime(n-2) else 'NO')
