from sys import stdout
a, b = map(int, input().split())
if a == b:
    stdout.write('0')
    exit(0)
if b < a:
    temp = a
    a = b
    b = temp
stdout.write(str(int(b-a-1))+'\n')
for i in range(a+1, b):
    stdout.write(str(i)+' ')