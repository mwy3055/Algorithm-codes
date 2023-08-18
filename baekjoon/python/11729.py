def hanoi(n, From, by, to):
    if n == 0:
        return

    hanoi(n-1, From, to, by)
    print(From, to)
    hanoi(n-1, by, From, to)


if __name__ == "__main__":
    n = int(input())
    a = list(map(lambda x: 0, range(20)))
    a[0] = 1
    for i in range(1, n):
        a[i] = 2*a[i-1]+1
    print(a[n-1])
    hanoi(n, 1, 2, 3)
