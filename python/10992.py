def star17(n):
    print(' '*(n-1)+'*')
    for i in range(2, n):
        print(' '*(n-i)+'*'+' '*(2*i-3)+'*')
    if 1 < n:
        print('*'*(2*n-1))


n = int(input())
star17(n)
