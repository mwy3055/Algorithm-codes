from collections import deque


class coord:
    def __init__(self, y, x):
        self.y = y
        self.x = x


def isin(i, j):
    global m, n
    return 0 <= i < m and 0 <= j < n


def bfs():
    global m, n, matter
    q = deque()
    visit=[[False for j in range(n)] for i in range(m)]
    src = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    for i in range(n):
        if matter[0][i] == '0':
            q.insert(0, coord(0, i))
            visit[0][i] = True
    while len(q):
        top = q.pop()
        y, x = top.y, top.x
        if y == m-1:
            return True
        for i in range(4):
            sy, sx = y+src[i][0], x+src[i][1]
            if isin(sy, sx) and matter[sy][sx] == '0' and visit[sy][sx] == False:
                q.insert(0, coord(sy, sx))
                visit[sy][sx] = True
    return False


m, n = map(int, input().split())
matter = [input().strip() for i in range(m)]
if bfs():
    print('YES')
else:
    print('NO')
