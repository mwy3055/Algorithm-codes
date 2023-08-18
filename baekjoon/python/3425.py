import sys
from collections import deque
input = sys.stdin.readline
LIMIT = int(1e9)


def pop(gostack):
    if len(gostack):
        gostack.pop()
        return True
    else:
        return False


def inv(gostack):
    if len(gostack):
        right = gostack.pop()
        gostack.append(-right)
        return True
    else:
        return False


def dup(gostack):
    if len(gostack):
        top = gostack.pop()
        gostack.append(top)
        gostack.append(top)
        return True
    else:
        return False


def swp(gostack):
    if len(gostack) < 2:
        return False
    else:
        first, second = gostack.pop(), gostack.pop()
        gostack.append(first)
        gostack.append(second)
        return True


def add(gostack):
    if len(gostack) < 2:
        return False
    else:
        result = gostack.pop()+gostack.pop()
        if LIMIT < abs(result):
            return False
        gostack.append(result)
        return True


def sub(gostack):
    if len(gostack) < 2:
        return False
    else:
        first, second = gostack.pop(), gostack.pop()
        result = second-first
        if LIMIT < abs(result):
            return False
        gostack.append(result)
        return True


def mul(gostack):
    if len(gostack) < 2:
        return False
    else:
        result = gostack.pop()*gostack.pop()
        if LIMIT < result:
            return False
        gostack.append(result)
        return True


def div(gostack):
    if len(gostack) < 2:
        return False
    else:
        first, second = gostack.pop(), gostack.pop()
        if first == 0:
            return False
        result = abs(second)//abs(first)
        if first*second < 0:
            gostack.append(-result)
        else:
            gostack.append(result)
        return True


def mod(gostack):
    if len(gostack) < 2:
        return False
    else:
        first, second = gostack.pop(), gostack.pop()
        if first == 0:
            return False
        result = abs(second) % abs(first)
        gostack.append(result if second > 0 else -result)
        return True


def num(command, gostack):
    x = int(command.split()[1])
    gostack.append(x)


def solve(commands, val):
    gostack = deque()
    gostack.append(val)
    for command in commands:
        if command == 'POP':
            if not pop(gostack):
                return None
        elif command == 'INV':
            if not inv(gostack):
                return None
        elif command == 'DUP':
            if not dup(gostack):
                return None
        elif command == 'SWP':
            if not swp(gostack):
                return None
        elif command == 'ADD':
            if not add(gostack):
                return None
        elif command == 'SUB':
            if not sub(gostack):
                return None
        elif command == 'MUL':
            if not mul(gostack):
                return None
        elif command == 'DIV':
            if not div(gostack):
                return None
        elif command == 'MOD':
            if not mod(gostack):
                return None
        elif command == 'END':
            break
        else:
            num(command, gostack)
    if len(gostack) == 1:
        return gostack[0]
    else:
        return None


while True:
    commands = deque()
    s = input().strip()
    if s == 'QUIT':
        break
    commands.append(s)
    while s != 'END':
        s = input().strip()
        commands.append(s)
    n = int(input())
    inputs = [int(input()) for _ in range(n)]
    input()

    for val in inputs:
        rtn = solve(commands, val)
        if rtn == None:
            print('ERROR')
        else:
            print(rtn)
    print()
