#include <bits/stdc++.h>

int dp[20][5];

int solve(int n, int state)
{
    if (n == 0)
        return dp[n][state] = (state == 0);
    else if (n < 0)
        return 0;
    auto &ret = dp[n][state];
    if (ret != -1)
        return ret;
    ret = 0;
    if (state == 0)
        ret = solve(n - 1, 0) + solve(n - 1, 1) + solve(n - 2, 0) + solve(n - 1, 3) + solve(n - 1, 4);
    else if (state == 1)
        ret = solve(n - 1, 0) + solve(n - 1, 4);
    else if (state == 2)
        ret = solve(n - 1, 3);
    else if (state == 3)
        ret = solve(n - 1, 0) + solve(n - 1, 2);
    else // 4
        ret = solve(n - 1, 4) + solve(n - 1, 0);
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << solve(n, 0) << '\n';
    }
}