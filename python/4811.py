import sys

input = sys.stdin.readline

dp = [[-1 for _ in range(32)] for _ in range(32)]


def solve(w, h):
    if dp[w][h] != -1:
        return dp[w][h]
    if h < 0:
        return 0
    if w == 0 and h == 0:
        dp[w][h] = 0
        return dp[w][h]
    elif w == 0:
        dp[w][h] = 1
        return dp[w][h]
    dp[w][h] = solve(w, h-1)+solve(w-1, h+1)
    return dp[w][h]


while True:
    n = int(input().strip())
    if n == 0:
        break
    print(solve(n, 0))
