from collections import deque
from sys import stdin, stdout


def balanced(line):
    s = deque()
    for c in line:
        if c == '(' or c == '[':
            s.appendleft(c)
        elif c == ')':
            if (not s) or s[0] != '(':
                return False
            s.popleft()
        elif c == ']':
            if (not s) or s[0] != '[':
                return False
            s.popleft()
        else:
            pass

    empty = False if s else True
    return empty


if __name__ == "__main__":
    for line in stdin:
        if line[0] == '.':
            exit(0)
        stdout.write(('yes' if balanced(line.strip()) else 'no')+'\n')
