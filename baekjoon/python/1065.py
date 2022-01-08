from sys import stdin
def solve(p):
    num, t = 0, 101
    while t <= p:
        t_h, t_t, t_m = t // 100, (t % 100) // 10, t % 10
        if 2 * t_t == t_h + t_m:
            num += 1
        t += 1
    return num + 99
num = int(stdin.readline())
if num < 100:
    print(num)
elif num == 100:
    print(99)
elif num == 1000:
    print(144)
else:
    print(solve(num))
