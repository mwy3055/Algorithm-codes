#include <bits/stdc++.h>

int dp[101][101][2];

// p로 시작하는 n자리 수열 중 인접한 비트가 k개인 수열
int search(int n, int k, int p)
{
    if (n <= 0 || k < 0)
        return 0;
    auto &ret = dp[n][k][p];
    if (ret != -1)
        return ret;
    if (n == 0)
        return ret = 0;
    if (k == 0)
    {
        if (p)
            return ret = search(n - 2, 0, 0) + search(n - 2, 0, 1);
        else
            return ret = search(n - 1, 0, 0) + search(n - 1, 0, 1);
    }
    if (k > n - 1)
        return ret = 0;

    int a = search(n - 1, k, 0);
    int b = search(n - 1, (p ? k - 1 : k), 1);

    return ret = a + b;
}

int solve(int n, int k)
{
    int a = search(n, k, 0);
    int b = search(n, k, 1);
    return a + b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::memset(dp, -1, sizeof(dp));
    dp[1][0][0] = dp[1][0][1] = 1;
    dp[1][1][0] = dp[1][1][1] = 0;
    dp[2][0][0] = 2;
    dp[2][0][1] = 1;
    dp[2][1][0] = 0;
    dp[2][1][1] = 1;

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << solve(n, k) << '\n';
    }
}