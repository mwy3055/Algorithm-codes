# submit to pypy
def getstr(n, i):
    s = str(i)
    if len(s) < n:
        s = '0'*(n-len(s))+s
    return s


def full(s):
    global m
    for must in m:
        if must not in s:
            return False
    return True


n, k = map(int, input().split())
if k == 0:
    print(10**n)
    exit(0)
m = set(input().split())

ans = 0
for i in range(10**(n)):
    s = getstr(n, i)
    if full(s):
        ans += 1
print(ans)
