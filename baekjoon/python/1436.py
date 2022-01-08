n = int(input())
nth, num = 1, 666
while nth < n:
    num += 1
    if(str(num).find('666') != -1):
        nth += 1
print(num)
