#include <bits/stdc++.h>

int eval(int a, int b, int c, int x)
{
    return a * x * x + b * x + c;
}

bool check1(int a, int b, int c)
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = i + 1; j <= 6; j++)
        {
            int n = 1 << i, m = 1 << j;
            if (eval(a, b, c, n) == 0 && eval(a, b, c, m) == 0)
                return true;
        }
    }
    return false;
}

bool check2(int a, int b, int c)
{
    int det = b * b - 4 * a * c;
    if (det <= 0)
        return false;
    int i = -1;
    for (int j = 1; j <= 10000; j++)
    {
        if (j * j == det)
        {
            i = j;
            break;
        }
    }
    if (i == -1)
        return false;
    int x1 = -b + i, x2 = -b - i;
    return x1 % (2 * a) == 0 && x2 % (2 * a) == 0;
}

int solve(int a, int b, int c)
{
    if (check1(a, b, c))
        return 0;
    else if (check2(a, b, c))
        return 1;
    else
        return 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b, c;
    std::cin >> a >> b >> c;
    // UTF-8 korean compatibility
    std::string answer[] = {"solve1", "solve2", "solve3"};
    int ans = solve(a, b, c);
    std::cout << answer[ans];
}