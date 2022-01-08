from sys import stdin
ch = [list(line[:-1]) for line in stdin]
l = [len(lis) for lis in ch]
for i in range(15):
    for j in range(5):
        if(l[j] <= i):
            continue
        print(ch[j][i], end = '')
