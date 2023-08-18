from math import sqrt
R, B = map(int, input().strip().split())
b = R//2+2
c = int(sqrt(b*b-4*(R+B)))
L, W = (b+c)//2, (b-c)//2
print(str(L)+' '+str(W))
