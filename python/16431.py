br, bc = map(int, input().split())
dr, dc = map(int, input().split())
jr, jc = map(int, input().split())
daisy = abs(dr-jr)+abs(dc-jc)
bessie = max(abs(br - jr), abs(bc - jc))
if bessie < daisy:
    print('bessie')
elif daisy < bessie:
    print('daisy')
else:
    print('tie')
