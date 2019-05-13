def haming(s1, s2):
    l = len(s1)
    ans = 0
    for i in range(l):
        if s1[i] != s2[i]:
            ans += 1
    return ans


t = int(input())
for i in range(t):
    print('Hamming distance is %d.' % haming(input(), input()))
