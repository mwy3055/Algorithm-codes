plus, minus = map(int, input().split())
a = (plus+minus)//2
b = plus-a
if 0 <= a and 0 <= b and a+b == plus and a-b == minus:
    print(a, b)
else:
    print(-1)
