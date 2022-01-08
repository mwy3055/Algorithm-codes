from sys import stdin, stdout

n, m = map(int, stdin.readline().split())
name, num = dict(), dict()
for i in range(n):
    line = stdin.readline().strip()
    num[line] = i+1
    name[i+1] = line
for i in range(m):
    line = stdin.readline().strip()
    if line.isdigit():
        stdout.write(name[int(line)]+'\n')
    else:
        stdout.write(str(num[line])+'\n')
