from sys import stdin
import statistics as stat

n = int(stdin.readline())
if n == 0:
    print(0)
    exit(0)
discuss = [int(stdin.readline()) for _ in range(n)]
discuss.sort()
cut = int(n*15/100+0.5)
print(int(stat.mean(discuss[cut:n-cut])+0.5))
