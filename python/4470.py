from sys import stdin, stdout
stdin.readline()
i = 1
for line in stdin:
    stdout.write(str(i)+'. '+line)
    i += 1