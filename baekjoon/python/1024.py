def exists(n, l):
    a = (n-(l-1)*l/2)/l
    if a >= 0 and float(int(a)) == a:
        return int(a), l
    else:
        return None, None


n, l = map(int, input().split())
a, length = None, None
for i in range(l, 101):
    a, length = exists(n, i)
    if a is not None:
        break
if a is not None:
    for i in range(length):
        print(a+i, end=' ')
else:
    print(-1)
