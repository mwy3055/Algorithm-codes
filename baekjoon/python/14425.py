from sys import stdin, stdout


def isin(sets, s):
    for elements in sets:
        if s == elements:
            return True
    return False


if __name__ == "__main__":
    n, m = map(int, stdin.readline().split())
    sets = list()
    for i in range(n):
        sets.append(stdin.readline().strip())
    ans = 0
    for i in range(m):
        if isin(sets, stdin.readline().strip()):
            ans += 1
    stdout.write(str(ans))
