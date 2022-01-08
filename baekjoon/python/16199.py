by, bm, bd = map(int, input().split())
cy, cm, cd = map(int, input().split())
dy, dm, dd = cy-by, cm-bm, cd-bd
if dd < 0:
    dm -= 1
if dm < 0:
    dy -= 1
print(dy)
print(cy-by+1)
print(cy-by)
