for a in range(2, 101):
    for b in range(2, a):
        for c in range(b, a):
            for d in range(c, a):
                if a**3 == b**3+c**3+d**3:
                    print('Cube = %d, Triple = (%d,%d,%d)' % (a, b, c, d))
