def solve():
    n = int(input())
    clothes = dict()
    for _ in range(n):
        name, kind = input().split()
        if kind not in clothes:
            clothes[kind] = 1
        else:
            clothes[kind] += 1
    # 선택하지 않거나 value개의 옷 중 하나를 선택
    nums = [value + 1 for value in clothes.values()]
    ans = 1
    for num in nums:
        ans *= num
    return ans - 1  # 모두 선택하지 않는 경우를 제외


t = int(input())
for _ in range(t):
    print(solve())
