#include <bits/stdc++.h>

int dp[10001][4];

int solve(int n, int min)
{
    if (n < 0)
        return 0;

    auto &ret = dp[n][min];
    if (n < min)
        return ret = 0;
    else if (n == min)
        return ret = 1;
    if (ret != -1)
        return ret;

    // min + ...으로 n을 만들자
    ret = 0;
    for (int i = min; i <= 3; i++)
    {
        ret += solve(n - min, i);
    }
    return ret;
}

int solve(int n)
{
    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans += solve(n, i);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::memset(dp, -1, sizeof(dp));

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        std::cout << solve(n) << '\n';
    }
}