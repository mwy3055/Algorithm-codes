def gms(n):
    for c in str(n):
        if not (c == '4' or c == '7'):
            return False
    return True


n = int(input())
while(not gms(n)):
    n -= 1
print(n)
