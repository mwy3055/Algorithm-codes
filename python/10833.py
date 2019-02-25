from sys import stdin
t=int(stdin.readline())
ans=0
for i in range(t):
    a,b=map(int,stdin.readline().split())
    ans+=b%a
print(ans)
