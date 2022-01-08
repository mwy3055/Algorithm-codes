import sys
input = sys.stdin.readline

n = int(input())
x, y = [0 for _ in range(51)], [0 for _ in range(51)]

ans = 0
for _ in range(n):
    p, tsum = int(input()), 0
    for i in range(1, p+1):
        x[i], y[i] = map(int, input().split())
    tsum = x[p]*y[1]-x[1]*y[p]
    for i in range(1, p):
        tsum += (x[i]*y[i+1]-x[i+1]*y[i])
    ans += abs(tsum)/2

print(int(ans))
