from sys import stdin, stdout
s = [False for i in range(20)]
m = int(stdin.readline())
for i in range(m):
    op = stdin.readline().split()
    if op[0] != 'all' and op[0] != 'empty':
        x = int(op[1])
    op = op[0]
    if op == 'add':
        s[x-1] = True
    elif op == 'remove':
        s[x-1] = False
    elif op == 'check':
        stdout.write(int(s[x-1])+'\n')
    elif op == 'toggle':
        s[x-1] = not s[x-1]
    elif op == 'all':
        for i in range(20):
            s[i] = True
    else:
        for i in range(20):
            s[i] = False