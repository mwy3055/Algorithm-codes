from sys import stdin
def sq(n):
    return n*n

def solve():
    count = 0
    x1,y1,x2,y2 = map(int,stdin.readline().rsplit())
    n = int(stdin.readline())
    for i in range(n):
        x, y, r = map(int, stdin.readline().rsplit())
        if (sq(x-x1)+sq(y-y1)<sq(r)) ^ (sq(x-x2)+sq(y-y2)<sq(r)):
            count += 1
    return count

t = int(stdin.readline())
for i in range(t):
    print(solve())
