def gcd(a, b):
    if a > b:
        a, b = b, a
    if b % a != 0:
        return gcd(a, b % a)
    else:
        return a


# ax + by = gcd(a, b)가 되는 x와 y를 반환
def euclid(a, b):
    if b != 0:
        tx, ty = euclid(b, a % b)
        return (ty, tx-(a//b)*ty)
    else:
        return (1, 0)


def solve(k, c):
    if gcd(k, c) != 1:
        return "IMPOSSIBLE"
    # kx + cy = 1을 만족하는 x, y 계산
    x, y = euclid(k, c)
    # inv: cy = 1 mod k를 만족하는 y
    # y가 음수일 수 있으므로 양수로 바꿔주고
    inv = (y+k) % k
    # c*inv(사탕 수)가 k 이상이어야 하므로
    while c*inv <= k:
        inv += k
    if inv > 1e9:
        return "IMPOSSIBLE"
    else:
        return inv


n = int(input())
for _ in range(n):
    k, c = map(int, input().split())
    print(solve(k, c))
