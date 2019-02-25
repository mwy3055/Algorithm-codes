from sys import stdin
from math import ceil, sqrt
check = [False for i in range(1000002)]
min, max = map(int, stdin.readline().rsplit())
r = int(sqrt(max))
for i in range(2, r + 1):
    sq = i * i
    for j in range(ceil(min/sq) * sq, max + 1, sq):
        if min <= j and j <= max:
            check[j - min] = True
cnt = 0
for i in range(min, max + 1):
     if check[i - min] == True:
          cnt += 1
print(max - min + 1 - cnt)
