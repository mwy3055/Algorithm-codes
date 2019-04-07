from sys import stdin, stdout
t, i = int(stdin.readline()), 1
for line in stdin:
    line = line.strip()
    c = line[-1].lower()
    if c == 'y':
    	a = 'nobody'
    elif c in 'aeiou':
    	a = 'a queen'
    else:
    	a = 'a king'
    stdout.write('Case #%d: %s is ruled by %s.\n' % (i, line, a))
    i += 1
