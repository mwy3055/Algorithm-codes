from sys import stdin
def vertical(n, room):
    vroom = ['' for i in range(n)]
    cnt = 0
    for line in room:
        i = 0
        for tile in line:
            vroom[i]+=tile
            i += 1
    for line in vroom:
        tokens = line.split('X')
        for token in tokens:
            if 2 <= len(token):
                cnt += 1
    return cnt
def horizontal(n, room):
    cnt = 0
    for line in room:
        tokens = line.split('X')
        for token in tokens:
            if 2 <= len(token):
                cnt += 1
    return cnt
n = int(stdin.readline())
room = [line[:-1] for line in stdin]
print("%d %d" %(horizontal(n, room), vertical(n, room)))
