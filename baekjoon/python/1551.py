def convert(A, n):
    B = [0 for i in range(n-1)]
    for i in range(n-1):
        B[i] = A[i+1]-A[i]
    return B


n, k = map(int, input().split())
A = list(map(int, input().split(',')))
for i in range(k):
    A = convert(A, n-i)

for i, num in enumerate(A):
    if i+1 == n-k:
        print(num)
        break
    else:
        print('%d,' % num, end='')
