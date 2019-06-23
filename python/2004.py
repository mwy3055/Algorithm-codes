def trtwo(n):
    cnt = 0
    while n:
        cnt += n//2
        n //= 2
    return cnt


def trfive(n):
    cnt = 0
    while n:
        cnt += n//5
        n //= 5
    return cnt


def trzero(n, m):
    tr2 = trtwo(n)-trtwo(m)-trtwo(n-m)
    tr5 = trfive(n)-trfive(m)-trfive(n-m)
    return tr2 if tr2 < tr5 else tr5


n, m = map(int, input().split())
print(trzero(n, m))
