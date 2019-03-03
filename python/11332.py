from sys import stdin, stdout
import math
for i in range(int(stdin.readline())):
    s, n, t, l = stdin.readline().split()
    n = int(n)
    t = int(t)
    l = int(l)*100000000
    if s == 'O(N)':
        flag = n*t <= l
    elif s == 'O(N^2)':
        flag = (n*n)*t <= l
    elif s == 'O(N^3)':
        flag = (n*n*n)*t <= l
    elif s == 'O(N!)':
        i, flag = 1, True
        for a in range(1, n+1):
            i *= a
            if i*t > l:
                flag = False
                break
    else:
        i, flag = 1, True
        for a in range(n):
            i *= 2
            if i*t > l:
                flag = False
                break
    if flag:
        stdout.write('May Pass.\n')
    else:
        stdout.write('TLE!\n')
