def solve(n, k):
    l, r = 1, k
    while l <= r:
        mid, cnt = (l+r)//2, 0
        for i in range(1, n+1):
            cnt += min(mid//i, n)
        if cnt < k:
            l = mid+1
        else:
            ans, r = mid, mid-1
    return ans


n, k = int(input()), int(input())
print(solve(n, k))
