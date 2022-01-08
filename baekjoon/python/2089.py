def div(n):
    while n:
        yield n % 2
        n = (n//2)*(-1)
    return 0


n = int(input())
if n == 0:
    print(0)
    exit(0)
s = [i for i in div(n)]
s.reverse()
for i in s:
    print(i, end='')
