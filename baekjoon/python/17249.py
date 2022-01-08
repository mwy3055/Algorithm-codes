left, right = 0, 0
parse = input().split('^0^')
for c in parse[0]:
    if c == '@':
        left += 1
for c in parse[1]:
    if c == '@':
        right += 1
print('%d %d' % (left, right))
