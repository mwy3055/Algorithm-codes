#include <bits/stdc++.h>

using ll = long long;
const ll INF = (1LL) << 50;

int n, x[100000], p[100000];
ll dp[100000][2];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i] >> p[i];
    }
}

bool solve()
{
    // 0: 스킵x
    // 1: 스킵
    dp[0][0] = p[0], dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1][0] <= x[i])
        {
            dp[i][0] = dp[i - 1][0] + p[i];
        }
        else
            dp[i][0] = INF;

        dp[i][1] = dp[i - 1][0];
        if (dp[i - 1][1] <= x[i])
            dp[i][1] = std::min(dp[i][1], dp[i - 1][1] + p[i]);
        else if (dp[i][1] == 0)
            dp[i][1] = INF;
    }
    return std::min(dp[n - 1][0], dp[n - 1][1]) < INF;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    if (solve())
    {
        std::cout << "Kkeo-eok" << '\n';
    }
    else
    {
        std::cout << "Zzz" << '\n';
    }
}