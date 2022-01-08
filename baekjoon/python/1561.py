import sys
import math
from collections import deque, Counter

input = sys.stdin.readline


def lcm(a, b):
    return a*b//math.gcd(a, b)


def LCM(numbers):
    ans = 1
    for number in numbers:
        ans = lcm(ans, number)
    return ans


def solve(n, m, duration):
    if n <= m:
        return n
    if m == 1:
        return 1
    dur_lcm = LCM(duration)
    count_per_lcm = [dur_lcm//dur for dur in duration]
    sum_count = sum(count_per_lcm)
    remainder_n = n % sum_count
    dur_counter = Counter(duration)
    f = deque()
    f.append(m)
    for t in range(1, dur_lcm+1):
        plus = 0
        for dur in dur_counter:
            if t % dur == 0:
                plus += dur_counter[dur]
        f.append(f[t-1]+plus)
        if f[t] >= remainder_n:
            time = t
            break
    nth = remainder_n-f[time-1]
    count = 0
    for index, dur in enumerate(duration):
        if time % dur == 0:
            count += 1
        if count == nth:
            return index+1
    return -1
    # return f, t, nth


n, m = map(int, input().strip().split())
duration = list(map(int, input().strip().split()))
print(solve(n, m, duration))
