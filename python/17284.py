cost = [500, 800, 1000]
sum = 0
for order in map(int, input().split()):
    sum += cost[order-1]
print(5000-sum)
