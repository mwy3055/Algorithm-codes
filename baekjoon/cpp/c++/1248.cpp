#include <bits/stdc++.h>

int n, a[10];
char s[10][10];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::cin >> s[i][j];
        }
    }
}

bool matches(char sign, int val)
{
    if (sign == '-')
        return val < 0;
    else if (sign == '0')
        return val == 0;
    else
        return val > 0;
}

bool possible(int idx)
{
    int sum = 0;
    for (int i = idx; i >= 0; i--)
    {
        sum += a[i];
        if (!matches(s[i][idx], sum))
            return false;
    }
    return true;
}

void print()
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
}

bool solve(int i)
{
    if (i == n)
    {
        print();
        return true;
    }

    for (int val = -10; val <= 10; val++)
    {
        a[i] = val;
        if (!matches(s[i][i], val) || !possible(i))
            continue;
        if (solve(i + 1))
            return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve(0);
}