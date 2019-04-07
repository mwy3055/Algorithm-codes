from sys import stdin


def dp(i):
    global mem
    if i==0:
        return 1
    elif mem[i] != 0:
        return mem[i]
    else:
        mem[i] = dp(i-1)+2*dp(i-2)
        return mem[i]


mem = list(map(lambda n: 0, range(255)))
mem[1], mem[2] = 1, 3
for i in stdin:
    n = int(i)
    print(dp(n))
