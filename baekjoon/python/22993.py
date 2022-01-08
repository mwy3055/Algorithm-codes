from sys import stdin

input = stdin.readline

n = int(input())
a = list(map(int, input().split()))
jw, other = a[0], sorted(a[1:])
ans = True
for attack in other:
    if jw <= attack:
        ans = False
        break
    else:
        jw += attack
print('Yes' if ans else 'No')
