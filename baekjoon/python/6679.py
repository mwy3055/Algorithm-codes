from sys import stdout


def ten(i):
    rtn = 0
    while 10 <= i:
        rtn += i % 10
        i //= 10
    rtn += i
    return rtn


def twelve(i):
    rtn = 0
    while 12 <= i:
        rtn += i % 12
        i //= 12
    rtn += i
    return rtn


def sixteen(i):
    rtn = 0
    while 16 <= i:
        rtn += i % 16
        i //= 16
    rtn += i
    return rtn

for i in range(1000, 10000):
    if ten(i) == twelve(i) == sixteen(i):
        stdout.write(str(i)+'\n')
