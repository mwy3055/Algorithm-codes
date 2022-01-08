from sys import stdin
n = int(stdin.readline())
num = list()
for t in stdin.readline().rsplit():
    num.append(int(t))
num.sort()
print(num[0] * num[n - 1])
