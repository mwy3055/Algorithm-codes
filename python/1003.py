from sys import stdin
def fzro(n):
    if n==0:
        return 1
    elif n==1:
        return 0
    elif zro[n]!=0:
        return zro[n]
    zro[n] = fzro(n-1) + fzro(n-2)
    return zro[n]

def fone(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    elif one[n]!=0:
        return one[n]
    one[n] = fone(n-1) + fone(n-2)
    return one[n]

zro = list()
one = list()
t = int(stdin.readline())
for i in range(t):
    n = int(stdin.readline())
    zro = [0 for i in range(n + 2)]
    one = [0 for i in range(n + 2)]
    print('%d %d' %(fzro(n), fone(n)))
    
