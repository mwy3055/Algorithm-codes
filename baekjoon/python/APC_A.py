n = int(input())
count = 1
for i in range(1, 1_000_001):
    if i == n:
        break
    count += 1
    if '50' in str(i):
        count += 1
print(count)
