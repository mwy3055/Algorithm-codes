n = int(input())
a, b = 1, 1
if n == 1 or n == 2:
    print(1)
else:
    for i in range(n-2):
        backup = b
        b = a + b
        a = backup
    print(b)
