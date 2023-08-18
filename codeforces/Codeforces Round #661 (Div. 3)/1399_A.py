t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    ans = True
    for i in range(n-1):
        if abs(a[i]-a[i+1]) > 1:
            ans = False
            break
    print("YES" if ans else "NO")
