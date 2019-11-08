def macro(cmd):
    return cmd[0] == cmd[1] == cmd[4] and cmd[2] == cmd[3] == cmd[5] == cmd[6] and cmd[0] != cmd[2]


t = int(input())
for _ in range(t):
    inp = input().strip()
    if len(inp) == 7 and macro(inp):
        print(1)
    else:
        print(0)
