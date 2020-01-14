for _ in range(int(input())):
    s = input()
    ans = 0
    for n in range(65, 91):
        if chr(n) not in s:
            ans += n
    print(ans)
