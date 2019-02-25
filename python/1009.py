from sys import stdin
t = int(stdin.readline())
for i in range(t):
    a,b = map(int, stdin.readline().rsplit())
    cnt = 1
    if a==1:
        print(1)
        continue
    init = a % 10
    fin = (a * a) % 10
    while init != fin:
        fin = (fin * a) % 10
        cnt += 1
    temp = (b - 1) % cnt + 1
    print((((a**temp)-1)%10)+1)
