import sys

d = [[0 for _ in range(201)] for _ in range(201)]
n, m = int(sys.stdin.readline()), int(sys.stdin.readline())
for i in range(1, n+1):
    column = map(int, sys.stdin.readline().split())
    for j, c in enumerate(column):
        d[i][j+1] = c
    d[i][i] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i != k and i != j and j != k:
                d[i][j] |= d[i][k] & d[k][j]

plan = list(map(int, sys.stdin.readline().split()))
ans = True
for i in range(len(plan)-1):
    if d[plan[i]][plan[i+1]] == 0:
        ans = False
        break
print("YES" if ans else "NO")
