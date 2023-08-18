# -로 분리한 다음
# 맨 처음 숫자에서 전부 빼면 된다.


def sum(tokens):
    ans = 0
    for token in tokens.split('+'):
        ans += int(token)
    return ans


tokens = input().strip().split('-')
ans = int(sum(tokens[0]))
for token in tokens[1:]:
    ans -= sum(token)
print(ans)
