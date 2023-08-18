from sys import stdin
n, m = map(int, stdin.readline().rsplit())

min = 0x7fffffff
map = []
def solve(x, y):
    global map
    cnt = 0
    for j in range(8):
        for i in range(8):
            if j%2==0:
                if i%2==0 and map[j+y][i+x]=='W':
                    cnt+=1
                if i%2==1 and map[j+y][i+x]=='B':
                    cnt+=1
            else:
                if i%2==0 and map[j+y][i+x]=='B':
                    cnt+=1
                if i%2==1 and map[j+y][i+x]=='W':
                    cnt+=1
    return cnt
for i in range(n):
    map.append(stdin.readline())
for y in range(n - 7):
    for x in range(m - 7):
        temp = solve(x, y)
        if(32 < temp):
            temp = 64 - temp
        if(temp < min):
            min = temp
print(min)
