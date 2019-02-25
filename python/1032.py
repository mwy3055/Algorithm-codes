from sys import stdin
n = int(stdin.readline())
common = stdin.readline()[:-1]
length = len(common)
for i in range(n-1):
    temp = stdin.readline()[:-1]
    for j in range(length):
        if common[j] == '?':
            continue
        elif common[j] != temp[j]:
            common = common[:j] + '?' + common[j+1:]
print(common)
