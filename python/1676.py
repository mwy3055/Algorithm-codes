n = int(input())
two, five = 0, 0
for i in range(1, n+1):
    c1, c2 = 0, 0
    t = i
    while t%2 == 0:
        t /= 2
        c1 += 1
    two += c1
    while i%5 == 0:
        i /= 5
        c2 += 1
    five += c2
print(min(two, five))
