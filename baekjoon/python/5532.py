num = [int(input()) for _ in range(5)]
print(num[0]-max((num[1]-1)//num[3]+1, (num[2]-1)//num[4]+1))
