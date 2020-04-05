import sys
input = sys.stdin.readline
sys.setrecursionlimit(2500)

comb = [[0 for _ in range(201)] for _ in range(201)]


def getcomb(n, k):
    if n == k or k == 0:
        comb[n][k] = 1
        return comb[n][k]
    if comb[n][k] != 0:

        return comb[n][k]
    comb[n][k] = getcomb(n-1, k)+getcomb(n-1, k-1)
    return comb[n][k]


def solve(k, dleft, oleft):
    if dleft == 0:
        return 'o'*oleft
    if oleft == 0:
        return '-'*dleft
    ifdash = getcomb(dleft+oleft-1, dleft-1)
    if k <= ifdash:
        return '-'+solve(k, dleft-1, oleft)
    else:
        return 'o'+solve(k-ifdash, dleft, oleft-1)


getcomb(200, 200)

for _ in range(int(input().strip())):
    n, m, k = map(int, input().strip().split())
    print(solve(k, n, m))
