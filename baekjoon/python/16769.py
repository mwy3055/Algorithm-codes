c, m = [], []  # c: capacity, m: current amount
for i in range(3):
    ci, mi = map(int, input().split())
    c.append(ci), m.append(mi)
for i in range(100):
    # (i%3) -> ((i+1)%3)
    fr, to = i % 3, (i+1) % 3
    if m[fr]+m[to] <= c[to]:
        m[to] += m[fr]
        m[fr] = 0
    else:
        can = c[to]-m[to]
        m[to] = c[to]
        m[fr] -= can
for i in range(3):
    print(m[i])
