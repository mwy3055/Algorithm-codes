from sys import stdin, stdout
n = int(stdin.readline())
ans = 0
st = stdin.readline().strip()
ch = [0 for i in range(26)]
clen = len(st)
for char in st:
    ch[ord(char)-65] += 1
for q in range(n-1):
    word = stdin.readline().strip()
    if abs(clen-len(word)) >= 2:
        continue
    c = [0 for i in range(26)]
    for char in word:
        c[ord(char)-65] += 1
    flag = 0
    flag2 = True
    for i in range(26):
        t = ch[i]-c[i]
        if t == 0:
        	continue
        if t == 1 or t == -1:
            flag += 1
        else:
        	flag2 = False
        	break
    if flag <= 2 and flag2:
        ans += 1
stdout.write(str(ans))