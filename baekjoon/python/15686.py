from sys import stdin
class coord:
    def __init__(self, y, x):
        self.y, self.x = y, x
            
def fill():
    global hidx
    for i in range(hidx):
        dist[i] = INF
def distance(s, h):
    return abs(s.x-h.x) + abs(s.y-h.y)

def solve():
    fill()
    global sidx, hidx, dist
    for i in range(sidx):
        if selected[i]:
            for j in range(hidx):
                dist[j] = min(dist[j], distance(store[i], house[j]))
    tmin = 0
    for i in range(hidx):
        tmin += dist[i]
    global ans
    ans = min(ans, tmin)

def dfs(dep, icl):
    global m, selected
    if icl==m:
        solve()
        return;
    global sidx
    if(sidx-dep<m-icl):
        return
    selected[dep]=True
    dfs(dep+1,icl+1)
    selected[dep]=False
    dfs(dep+1,icl)

INF=0x7fffffff
sidx, hidx, ans, n, m = 0, 0, INF, 0, 0
n, m = map(int, stdin.readline().rsplit())
store = [coord(0, 0) for i in range(13)]
selected = [False for i in range(13)]
house = [coord(0, 0) for i in range(2*n)]
for i in range(n):
    j = 0
    for obj in stdin.readline().rsplit():
        if obj=='1':
            house[hidx]=coord(i, j)
            hidx += 1
        elif obj=='2':
            store[sidx]=coord(i,j)
            sidx+=1
        j+=1
dist = [0 for i in range(hidx)]
dfs(0, 0)
print(ans)
