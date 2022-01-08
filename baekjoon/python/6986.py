import sys
import statistics as stat


def trimmed_mean(scores, n, k):
    return stat.mean(scores[k:n-k])


def adjusted_mean(scores, n, k):
    sum = 0
    for i in range(k, n - k):
        sum += scores[i]
    sum += (scores[k] + scores[n - k - 1]) * k
    return sum / n


n, k = map(int, sys.stdin.readline().split())
scores = [int(float(sys.stdin.readline())*10) for _ in range(n)]
scores.sort()
print("%.2f" % (trimmed_mean(scores, n, k) / 10 + 1e-9))
print("%.2f" % (adjusted_mean(scores, n, k) / 10 + 1e-9))
