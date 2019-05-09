from collections import Counter
from sys import stdin
from statistics import mean

num = list(map(int, stdin))
print(mean(num))
print(Counter.most_common(0)[0])
