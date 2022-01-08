#include <bits/stdc++.h>

int solve(int x)
{
    int cnt = 0;
    for (int digit = 1; digit <= 9; digit++)
    {
        bool found = false;
        int cur = digit;
        for (int len = 1; len <= 4; len++)
        {
            cnt += len;
            if (cur == x)
            {
                found = true;
                break;
            }
            cur = cur * 10 + digit;
        }
        if (found)
            break;
    }
    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int x;
        std::cin >> x;
        std::cout << solve(x) << '\n';
    }
}