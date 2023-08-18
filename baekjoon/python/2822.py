score = [[i+1, int(input())] for i in range(8)]
score = sorted(score, key=lambda x: x[1], reverse=True)
ans = 0
for i in range(5):
    ans += score[i][1]
print(ans)
for i in sorted(score[:5]):
    print(i[0], end=' ')
