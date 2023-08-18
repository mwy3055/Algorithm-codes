from sys import stdin
n = int(stdin.readline())
a = stdin.readline().rsplit()
b = stdin.readline().rsplit()
a.sort()
b.sort()
sum = 0
for i in range(n):
    sum += int(a[i])*int(b[n-1-i])
print(sum)
