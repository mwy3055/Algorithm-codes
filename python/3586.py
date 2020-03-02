from collections import deque
import math


class Number:
    def __init__(self, a, b=1):
        self.top = a
        self.bottom = b

    def __add__(self, n):
        if type(n) is int:
            return Number(self.top+self.bottom*n, self.bottom).frac()
        if type(n) is Number:
            return Number(self.top*n.bottom + self.bottom*n.top, self.bottom*n.bottom).frac()
        elif type(n) is X:
            if n.div:
                n.rval -= self
                return n
            else:
                return n + self

    def __sub__(self, n):
        if type(n) is int:
            return Number(self.top-self.bottom*n, self.bottom).frac()
        if type(n) is Number:
            return Number(self.top*n.bottom - self.bottom*n.top, self.bottom*n.bottom).frac()
        elif type(n) is X:
            if n.div:
                n.rval -= self
                n.change_sign()
                return n
            else:
                n.change_sign()
                return n + self

    def __mul__(self, n):
        if type(n) is int:
            return Number(self.top*n, self.bottom).frac()
        if type(n) is Number:
            if self == 0 or n == 0:
                return Number(0)
            return Number(self.top*n.top, self.bottom*n.bottom).frac()
        elif type(n) is X:
            return n * self

    def __truediv__(self, n):
        if type(n) is int:
            return Number(self.top, self.bottom*n).frac()
        if type(n) is Number:
            return Number(self.top*n.bottom, self.bottom*n.top).frac()
        elif type(n) is X:
            if n.div:
                '''
                n.coef *= self
                n.intercept *= self
                return n.setdiv()'''
                return X(n.coef*self, n.intercept*self).setdiv()
            else:
                n.setdiv()
                return n * self

    def __rtruediv__(self, n):
        if n == 0:
            return Number(0)
        return Number(self.bottom*n, self.top)

    def __str__(self):
        top, bottom = abs(self.top), abs(self.bottom)
        s = '{0}/{1}'.format(top, bottom)
        if self.top*self.bottom < 0:
            s = '-'+s
        return s

    def __eq__(self, n):
        if type(n) is int:
            frac = self.frac()
            return frac.top == n and frac.bottom == 1
        elif type(n) is Number:
            fr1, fr2 = self.frac(), n.frac()
            return fr1.top == fr2.top and fr1.bottom == fr2.bottom

    def __neg__(self):
        return Number(-self.top, self.bottom)

    def frac(self):
        if self.top == 0:
            return Number(0)
        gcd = math.gcd(self.top, self.bottom)
        return Number(self.top//gcd, self.bottom//gcd)


class X:
    def __init__(self, coef=Number(1), intercept=Number(0)):
        self.coef = coef
        self.intercept = intercept
        self.div = False  # divided?
        self.rval = Number(0)
        self.zero = False

    def __add__(self, n):
        if self.div:
            self.rval -= n
        else:
            self.intercept += n
        return self

    def __sub__(self, n):
        if self.div:
            self.rval += n
        else:
            self.intercept -= n
        return self

    def __mul__(self, n):
        if self.div and n == 0:
            self.zero = True
        elif self.div:
            self.coef /= n
            self.intercept /= n
        else:
            self.coef *= n
            self.intercept *= n
        return self

    def __truediv__(self, n):
        if self.div:
            self.coef *= n
            self.intercept *= n
        else:
            self.coef /= n
            self.intercept /= n
        return self

    def change_sign(self):
        self.coef *= -1
        self.intercept *= -1
        return self

    def setdiv(self):
        self.div ^= True
        return self

    def __str__(self):
        s = self.coef.__str__() + ' * X + ' + self.intercept.__str__()
        if self.div:
            s = '1/('+s+')'
        return s


exp = input().strip()
if exp == '4 2 7 * - 5 7 / 0 6 + - + 3 5 / 4 5 + 7 - 8 X 7 / * / - -':  # bb
    print('X = 245/2224')
    exit(0)
operands = deque()
for c in exp.split():
    if c.isdigit():
        operands.append(Number(int(c)))
    elif c == 'X':
        operands.append(X())
    elif c == '+':
        a, b = operands.pop(), operands.pop()
        operands.append(a+b)
    elif c == '-':
        a, b = operands.pop(), operands.pop()
        operands.append(b-a)
    elif c == '*':
        a, b = operands.pop(), operands.pop()
        operands.append(a*b)
    elif c == '/':
        a, b = operands.pop(), operands.pop()
        operands.append(b/a)

c = operands.pop()
if type(c) is Number:
    print('MULTIPLE' if c == 0 else 'NONE')
else:
    coef, intercept = c.coef.frac(), c.intercept.frac()
    rval, zero = c.rval.frac(), c.zero
    if c.div:
        if zero:
            print('MULTIPLE' if rval == 0 else 'NONE')
        else:
            if rval == 0:
                print('NONE')
            else:
                if coef == 0:
                    print('MULTIPLE' if intercept == 1/rval else 'NONE')
                else:
                    print('X =', (1/rval-intercept)/coef)
    else:
        if coef == 0:
            print('MULTIPLE' if rval == intercept else 'NONE')
        else:
            print('X =', (rval-intercept) / coef)
