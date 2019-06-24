n = int(input())
nums = sorted(list(map(int, input().split())))
sum = 0
for i, num in enumerate(nums):
    sum += num*(2*i-2*(n-i-1))
print(sum)
