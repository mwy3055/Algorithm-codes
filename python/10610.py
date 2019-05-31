from sys import stdin, stdout


def mtp3(s):
    sum = 0
    flag = False
    for c in map(int, s):
        sum += c
        if c == 0:
            flag = True
    return sum % 3 == 0 and flag


s = input().strip()
if not mtp3(s):
    print(-1)
    exit(0)

s = sorted(list(map(int, s)), reverse=True)
for num in map(str, s):
    stdout.write(num)
