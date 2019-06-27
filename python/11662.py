# a, b, c를 각각 계수로 하는 이차함수의 최솟값 구하기
import math


def mindist(num):
    A = num[2]+num[4]-num[0]-num[6]
    B = num[0]-num[4]
    C = num[3]+num[5]-num[1]-num[7]
    D = num[1]-num[5]
    a = A*A+C*C
    b = 2*(A*B+C*D)
    c = B*B+D*D
    if a == 0:
        return math.sqrt(c)
    elif 0 <= -(b/(2*a)) <= 1:
        return math.sqrt(c-(b*b/(4*a)))
    else:
        return math.sqrt(min(c, a+b+c))


print("%.9f" % mindist(list(map(int, input().split()))))
