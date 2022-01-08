from sys import stdin, stdout
n = int(stdin.readline())
num=[int(line) for line in stdin]
#num = [int(stdin.readline()) for i in range(n)]
num.sort()
i, j, sum = n-1, 0, 0
while i >= 0 and num[i] > 1:
    if i-1 >= 0 and num[i-1] > 1:
            sum += num[i]*num[i-1]
            i -= 1
    else:
        sum += num[i]
    i -= 1
while j < n and num[j] <= 0:
    if j+1 < n and num[j+1] <= 0:
        sum += num[j]*num[j+1]
        j += 1
    else:
        sum += num[j]
    j += 1
for k in range(j, i + 1):
    sum += num[k]
stdout.write(str(sum))