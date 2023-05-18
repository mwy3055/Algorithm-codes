n, m = map(int, input().split())
if n == 0:
    print(0)
    exit(0)
box_count, box_weight = 0, 0
for book in map(int, input().split()):
    if box_weight+book <= m:
        box_weight += book
    else:
        box_count += 1
        box_weight = book
if box_weight != 0:
    box_count += 1
print(box_count)
