s, k = map(int, input().split())

'''
10 3 -> (3 3) 4
10 4 -> (2 2 2) (3 3) 
'''

sum = 1;

if (s // k == 0):
    print((s / k)**k)

else:
    r = s % k
    for i in range (0, k-r):
        sum *= s // k
    for i in range(0, r):
        sum *= (s//k + 1)
    print(sum)