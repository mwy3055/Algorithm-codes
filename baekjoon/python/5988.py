from sys import stdin, stdout
stdin.readline()
for line in stdin:
    if(int(line[-1])%2==1):
        stdout.write('odd\n')
    else:
        stdout.write('even\n')