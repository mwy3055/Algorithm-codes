from sys import stdin, stdout
for line in stdin:
    a, b = map(int, line.split())
    if a==0 and b==0:
        break
    if a>b:
        stdout.write('Yes\n')
    else:
        stdout.write('No\n')