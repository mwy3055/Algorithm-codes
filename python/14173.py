fx1, fy1, fx2, fy2 = map(int, input().split())
sx1, sy1, sx2, sy2 = map(int, input().split())
x1, y1, x2, y2 = min(fx1, sx1), min(fy1, sy1), max(fx2, sx2), max(fy2, sy2)
print(max((x2-x1), (y2-y1))**2)
