n=int(input())
t=list(map(lambda n:0, range(n+1)))
t[0]=1
for i in range(1, n+1):
    for j in range(i):
        t[i]+=t[j]*t[i-1-j]
print(t[n])