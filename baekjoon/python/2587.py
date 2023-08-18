from sys import stdin
nums=[int(i) for i in stdin]
nums.sort()
sum=0
for num in nums:
    sum+=num
print(sum//5)
print(nums[2])
