from sys import stdin

n, m = map(int, stdin.readline().split())
cards = [[0, 0] for i in range(n)]
for i in range(n):
    line = list(map(int, stdin.readline().split()))
    cards[i] = line

faces = [0 for i in range(n)]
for _ in range(m):
    k = int(stdin.readline())
    for i, card in enumerate(cards):
        if card[faces[i]] <= k:
            faces[i] = 1-faces[i]

sum = 0
for i in range(n):
    sum += card[faces[i]]
print(sum)
