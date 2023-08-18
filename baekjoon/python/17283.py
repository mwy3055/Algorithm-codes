l = int(input())
r = int(input())
sum, nth = 0, 2
while 5 < l*r//100:
    sum += nth*(l*r//100)
    nth *= 2
    l = l*r//100
print(sum)
