#include <bits/stdc++.h>

using ll = long long;

ll dp[1001][5];

int near(double d)
{
    return (int)(d + 0.5);
}

ll hanoi(int n, int stick)
{
    auto &ret = dp[n][stick];
    if (ret != -1)
        return ret;

    // Frame-Stewert algorithm
    int k = n - near(std::sqrt(2 * n + 1)) + 1;
    auto top_ans = hanoi(k, stick);
    auto bottom_ans = hanoi(n - k, stick - 1);
    return ret = top_ans * 2 + bottom_ans;
}

ll solve(int n)
{
    std::memset(dp, -1, sizeof(dp));
    dp[1][3] = dp[1][4] = 1;
    for (int i = 2; i < 1000; i++)
    {
        dp[i][3] = dp[i - 1][3] * 2 + 1;
    }
    return hanoi(n, 4);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    for (int i = 1; std::cin >> n; i++)
    {
        std::cout << "Case " << i << ": " << solve(n) << '\n';
    }
}