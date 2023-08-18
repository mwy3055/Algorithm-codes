# (제일 큰 수) - (제일 작은 수)의 약수를 1을 제외하고 모두 구한다.
# 각 약수로 나눠봤을 때 나머지가 모두 같다면 정답에 포함


def factor(n):
    factors = []
    i = 2
    while i*i <= n:
        if n % i == 0:
            factors.append(i)
            if i*i != n:
                factors.append(n // i)
        i += 1
    factors.sort()
    factors.append(n)
    return factors


n = int(input())
numbers = sorted([int(input()) for _ in range(n)])
answers = []
for fac in factor(numbers[-1] - numbers[0]):
    mod = numbers[0] % fac
    add = True
    for i in range(1, n):
        if numbers[i] % fac != mod:
            add = False
            break
    if add:
        answers.append(fac)
for answer in answers:
    print(answer, end=' ')
