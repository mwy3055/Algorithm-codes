def ispalin(s):
    for s1, s2 in zip(s, reversed(s)):
        if s1 != s2:
            return False
    return True


for _ in range(int(input())):
    n = input()
    temp = 0
    for c in reversed(n):
        temp = temp*10+int(c)
    s = int(n)+temp
    print(s)
    print('YES' if ispalin(str(s)) else 'NO')
