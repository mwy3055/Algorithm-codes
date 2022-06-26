#include <bits/stdc++.h>

int n, arr[50];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

bool check()
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            return true;
    }
    return false;
}

bool odd()
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            arr[i]--;
            return true;
        }
    }
    return false;
}

void divide()
{
    for (int i = 0; i < n; i++)
    {
        arr[i] /= 2;
    }
}

int solve()
{
    int count = 0;
    while (check())
    {
        if (odd())
        {
            count++;
            continue;
        }
        divide();
        count++;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}