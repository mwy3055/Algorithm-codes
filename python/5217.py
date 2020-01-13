t = int(input())
for _ in range(t):
    n = int(input())
    lis = list()
    for i in range(n):
        for j in range(i+1, n):
            if i != j and i+j == n:
                lis.append([i, j])
    print('Pairs for %d:' % n, end=' ')
    for i, pair in enumerate(lis):
        print(pair[0], pair[1], end='')
        if i < len(lis)-1:
            print(', ', end='')
    print()
