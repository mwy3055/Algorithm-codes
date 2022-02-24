#include <bits/stdc++.h>

int n, price[15][15], dp[1 << 16][15][10];

bool contains(int mask, int idx)
{
    return (mask & (1 << idx)) != 0;
}

int solve(int state, int cur, int pr)
{
    auto &ret = dp[state][cur][pr];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (pr <= price[cur][i] && !contains(state, i))
        {
            ret = std::max(ret, solve(state | (1 << i), i, price[cur][i]));
        }
    }
    return ret + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            std::cin >> c;
            price[i][j] = c - '0';
        }
    }
    std::cout << solve(1, 0, 0);
}