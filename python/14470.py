a, b, c, d, e = int(input()), int(input()), int(
    input()), int(input()), int(input())
ans, frozen = 0, True if a < 0 else True
while a < b:
    if a < 0:
        ans += c
        a += 1
    elif a == 0 and frozen:
        ans += d
        frozen = False
    else:
        ans += e
        a += 1
print(ans)
