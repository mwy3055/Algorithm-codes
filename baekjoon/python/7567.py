sum = 0
cs = list(input())
l = len(cs)
for i in range(l):
    if 0 < i and cs[i-1]==cs[i]:
        sum+=5
    else:
        sum+=10
print(sum)
