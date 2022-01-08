num=list(map(int,input().split()))
num.sort()
for char in input().strip():
    print(num[ord(char)-65], end=' ')