import sys

input = sys.stdin.readline


def tochar(i):
    return chr(ord('0')+i) if 0 <= i < 10 else chr(ord('A')+(i-10))


def toint(c):
    return ord(c)-ord('0') if '0' <= c <= '9' else 10+ord(c)-ord('A')


def to36(i):
    if i == 0:
        return '0'
    chars = list()
    while i > 0:
        chars.append(tochar(i % 36))
        i //= 36
    chars.reverse()
    return ''.join(chars)


n = int(input().strip())
sum = 0
increase = [0]*36
for _ in range(n):
    s = input().strip()
    sum += int(s, 36)
    l = len(s)
    for index, c in enumerate(s):
        c_int = toint(c)
        increase[c_int] += (toint('Z')-toint(c))*(36**(l-1-index))
k = int(input().strip())
increase.sort()
increase.reverse()
for i in range(k):
    sum += increase[i]
print(to36(sum))
