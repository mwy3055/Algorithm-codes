n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(m)]
C = [list(map(lambda _:0, range(k))) for _ in range(n)]

for c in range(m):
    for a in range(n):
        r = A[a][c]
        for b in range(k):
            C[a][b] += r*B[c][b]

for rows in C:
    for cols in rows:
        print(cols, end=' ')
    print()
