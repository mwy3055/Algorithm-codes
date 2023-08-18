import sys
from collections import deque
input = sys.stdin.readline

operators = [' ', '+', '-']
stack = deque()


def solve(n):
    search(n, 0)


def search(n, dep):
    if dep == n - 1:
        eval(n)
        return
    for op in operators:
        stack.append(op)
        search(n, dep + 1)
        stack.pop()


def eval(n):
    expr = list(' '.join([str(i) for i in range(1, n+1)]))
    for index, op in enumerate(stack):
        expr[2*index+1] = op
    expr_str = ''.join(expr)
    expr = list(map(int, expr_str.replace(' ', '').replace(
        '+', ' ').replace('-', ' ').split()))
    real_op = filter(lambda x: x != ' ', stack)
    ans = expr[0]
    for (elem, op) in zip(expr[1:], real_op):
        if op == '+':
            ans += elem
        else:
            ans -= elem
    if ans == 0:
        print(expr_str)


for _ in range(int(input())):
    n = int(input())
    solve(n)
    print()
