from sys import stdin
n,k=map(int,stdin.readline().split())
ans=1
for i in range(2,n+1):
    ans*=i
for i in range(2,k+1):
    ans=ans//i
for i in range(2,n-k+1):
    ans=ans//i
print(ans%1000000007)