from sys import stdin, stdout

s = set()
n = int(stdin.readline())
for i in range(n):
    name, record = stdin.readline().strip().split()
    if record == 'enter':
        s.add(name)
    else:
        s.remove(name)

l = sorted(list(s), reverse=True)
for name in l:
    stdout.write(name+'\n')
