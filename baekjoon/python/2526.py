n, p = map(int, input().split())
occur = [0 for _ in range(max(n, p)+1)]
num, idx = n, 1
occur[num] = idx
while True:
    idx += 1
    num = num*n % p
    if occur[num]:
        print(idx-occur[num])
        exit(0)
    occur[num] = idx
