from sys import stdin
from collections import deque
import math
input = stdin.readline


def check(num, k, dp, lis):
    if num == 0:
        dp[num] = True
        return True
    if num in dp:
        return dp[num]
    idx = int(math.log(num, k)+0.5)
    cur, ans = k**idx, False
    while cur:
        if cur <= num and check(num-cur, k, dp, lis):
            ans = True
            break
        cur //= k
        idx -= 1
    if ans:
        lis.append(idx)
    dp[num] = ans
    return ans


def solve(arr, k):
    rtn = deque()
    for num in arr:
        lis = deque()
        check(num, k, dict(), lis)
        rtn.append(lis)
    return rtn


for _ in range(int(input())):
    n, k = map(int, input().strip().split())
    arr = [int(i) for i in input().strip().split()]
    result = solve(arr, k)
    s, sumlen = set(), 0
    for res in result:
        s = s.union(res)
        sumlen += len(res)
    print('YES' if len(s) == sumlen else 'NO')
