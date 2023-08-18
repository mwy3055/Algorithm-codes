from sys import stdin


n, m = map(int, stdin.readline().split())
Ti = list(map(int, stdin.readline().split()))
sum, idx = 0, 1
for _ in range(m):
    sum += Ti[_]
ans = sum
while idx <= n-m:
    sum = sum - Ti[idx] + Ti[idx+m-1]
    print(sum)
    idx += 1
    ans = max(ans, sum)
print(ans)
