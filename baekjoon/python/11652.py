from collections import Counter
from sys import stdin
stdin.readline()
common = Counter([int(line) for line in stdin]).most_common()

i = 0
for j, elem in enumerate(common):
    if common[0][1] == elem[1]:
        i += 1
    else:
        break
print(sorted([common[a][0] for a in range(i)])[0])
