# pypy로 제출할 것
class circle:
    def __init__(self, line):
        self.x, self.y, self.r = map(int, line.strip().split())

    def isin(self, y, x):
        dy, dx = self.y-y, self.x-x
        return dy**2+dx**2 <= self.r**2


c1, c2, c3 = circle(input()), circle(input()), circle(input())
grid = [i/250 for i in range(1, 25001)]
ans = 0
for y in grid:
    for x in grid:
        if c1.isin(y, x) or c2.isin(y, x) or c3.isin(y, x):
            ans += 1
print(ans/(250**2))
