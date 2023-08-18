def star21(n):
    if n == 1:
        print('*')
        return

    for i in range(1, 2*n+1):
        for j in range(n):
            print(' ' if i & 1 == j & 1 else '*', end='')
        print()


n = int(input())
star21(n)
