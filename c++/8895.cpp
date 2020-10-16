#include <bits/stdc++.h>

using ll = long long;

ll dp[21][21][21];

// same as 1328
ll solve(int n, int l, int r)
{
    auto &ret = dp[n][l][r];
    if (ret != -1)
        return ret;
    if (n == 0)
        return ret = 0;
    if ((l == 1 && r == n) || (l == n && r == 1))
        return ret = 1;
    if (l == 0 || r == 0)
        return ret = 0;
    return ret = solve(n - 1, l, r) * (n - 2) + solve(n - 1, l - 1, r) + solve(n - 1, l, r - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, l, r;
        std::cin >> n >> l >> r;
        std::cout << solve(n, l, r) << '\n';
    }
}