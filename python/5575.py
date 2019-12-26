def calc(h1, m1, s1, h2, m2, s2):
    dh, dm, ds = h2-h1, m2-m1, s2-s1
    if ds < 0:
        dm -= 1
        ds += 60
    if dm < 0:
        dh -= 1
        dm += 60
    print(dh, dm, ds)


for _ in range(3):
    h1, m1, s1, h2, m2, s2 = map(int, input().split())
    calc(h1, m1, s1, h2, m2, s2)
