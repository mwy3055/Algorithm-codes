n, m = map(int, input().split())
add = [False for _ in range(n+1)]
for i in map(int, input().split()):
    temp = i
    while temp <= n:
        add[temp] = True
        temp += i
sum = 0
for i, val in enumerate(add):
    if val:
        sum += i
print(sum)
