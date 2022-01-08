from sys import stdin, stdout
a = [0 for i in range(10)]
b = a[:]
A, B = stdin.readline().split()
for c in A:
    a[int(c)] += 1
for c in B:
    b[int(c)] += 1
ans = 0
for i in range(10):
    for j in range(10):
        ans += i*j*a[i]*b[j]
stdout.write(str(ans))