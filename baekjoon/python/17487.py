left = 'qwertyasdfgzxcvb'
right = 'uiophjklnm'
lhand, rhand, middle = 0, 0, 0
S = input().strip()
for c in S:
    if c == ' ':
        middle += 1
        continue
    if c.isupper():
        middle += 1
    if c.lower() in left:
        lhand += 1
    else:
        rhand += 1
while middle:
    if lhand <= rhand:
        lhand += 1
    else:
        rhand += 1
    middle -= 1
print('%d %d' % (lhand, rhand))
