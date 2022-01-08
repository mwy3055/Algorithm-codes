def star15(n):
    print(' '*(n-1)+'*')
    for i in range(2, n+1):
        print(' '*(n-i)+'*'+' '*(2*i-3)+'*')


n = int(input())
if n % 2 == 0:
    print('I LOVE CBNU')
else:
    print('*'*n)
    star15(n//2+1)
