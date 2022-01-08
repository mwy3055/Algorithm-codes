n = int(input())
num = list(map(int, input().split()))
v = int(input())
ans = 0
for i in num:
    if i == v:
        ans += 1
print(ans)
