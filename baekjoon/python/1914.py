from sys import stdout


def hanoi(n, From, By, To):
    if n == 1:
        stdout.write('{0} {1}\n'.format(From, To))
        return
    hanoi(n-1, From, To, By)
    stdout.write('{0} {1}\n'.format(From, To))
    hanoi(n-1, By, From, To)


n = int(input())
ans = 0
for i in range(n):
    ans = ans*2+1
stdout.write('{0}\n'.format(ans))
if(n <= 20):
    hanoi(n, 1, 2, 3)
