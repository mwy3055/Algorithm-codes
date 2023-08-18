num_a = list(map(int, input().split()))
num_b = list(map(int, input().split()))
sc_a, sc_b, lastwin = 0, 0, 0  # A: 1, B: 2
for a, b in zip(num_a, num_b):
    if b < a:
        sc_a += 3
        lastwin = 1
    elif a < b:
        sc_b += 3
        lastwin = 2
    else:
        sc_a += 1
        sc_b += 1
print(sc_a, sc_b)
if sc_b < sc_a:
    print('A')
elif sc_a < sc_b:
    print('B')
else:
    if lastwin == 1:
        print('A')
    elif lastwin == 2:
        print('B')
    else:
        print('D')
