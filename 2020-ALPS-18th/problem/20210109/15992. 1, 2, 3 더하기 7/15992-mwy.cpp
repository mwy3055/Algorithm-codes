#include <bits/stdc++.h>

const int MOD = 1000000009;
int dp[1001][1001];

int solve(int n, int m)
{
    auto &ret = dp[n][m];
    if (ret != -1)
        return ret;
    if (n == 0)
        return ret = (m == 0);
    if (m == 1)
        return ret = (n <= 3);
    ret = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (n >= i)
            ret = (ret + solve(n - i, m - 1)) % MOD;
    }
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
        int n, m;
        std::cin >> n >> m;
        std::cout << solve(n, m) << '\n';
    }
}