from sys import stdin, stdout
while True:
    n = int(stdin.readline())
    if n == 0:
        break
    s = [stdin.readline().strip() for i in range(n)]
    i, j = 0, 0
    while j < n:
        l = len(s[j])
        while i < l and s[j][i] != ' ':
            i += 1
        j += 1
    stdout.write(str(i-1)+'\n')