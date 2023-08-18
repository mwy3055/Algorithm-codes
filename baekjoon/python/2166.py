import sys
input = sys.stdin.readline

n = int(input())
x, y = [0 for _ in range(n+1)], [0 for _ in range(n+1)]
for i in range(1, n+1):
    x[i], y[i] = map(int, input().split())
sum = x[n]*y[1]-x[1]*y[n]

for i in range(1, n):
    sum += (x[i]*y[i+1]-x[i+1]*y[i])
print('%.1f' % (abs(sum)/2))
