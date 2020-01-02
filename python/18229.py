n, m, k = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
hand = [0 for i in range(n)]
for j in range(m):
    for i in range(n):
        hand[i] += A[i][j]
        if k <= hand[i]:
            print(i+1, j+1)
            exit(0)
