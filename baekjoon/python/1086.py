import sys
import math
input = sys.stdin.readline


def nlen(n):
    rtn = 0
    while n:
        n //= 10
        rtn += 1
    return rtn


n = int(input().strip())
arr = [int(input().strip()) for _ in range(n)]
k = int(input().strip())

len = [nlen(i) for i in arr]
tmod = [(10**i) % k for i in range(51)]
# dp[i][j]: 고른 수의 집합이 i(비트마스크)일 때 나머지가 j인 경우의 수
dp = [[0 for _ in range(k)] for _ in range((1 << n)+1)]
dp[0][0] = 1

for bit in range((1 << n)):
    for j in range(k):
        for i in range(n):
            if bit & (1 << i) == 0:
                nbit = bit | (1 << i)
                nmod = ((j*tmod[len[i]] % k) + arr[i] % k) % k
                dp[nbit][nmod] += dp[bit][j]


ans = dp[(1 << n)-1][0]
if ans == 0:
    print('0/1')
else:
    fac = math.factorial(n)
    gcd = math.gcd(fac, ans)
    print('%d/%d' % (ans//gcd, fac//gcd))
