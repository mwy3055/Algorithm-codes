#include <bits/stdc++.h>

int n, k, m, len[50], q[50];
double dp[5][50], t[50][50];
const int MOD = 5;

void getinput()
{
    std::cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> len[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> t[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> q[i];
    }
}

double calc(int i, int j)
{
    double ans = 0;
    for (int t = 0; t < len[j]; t++)
        ans += dp[(i - t) % MOD][j];
    return ans;
}

void solve()
{
    dp[0][0] = 1;
    for (int time = len[0]; time <= k; time++)
    {
        for (int cur = 0; cur < n; cur++)
        {
            auto &cur_dp = dp[time % MOD][cur];
            cur_dp = 0;
            for (int song = 0; song < n; song++)
            {
                if (time - len[song] >= 0)
                    cur_dp += dp[(time - len[song]) % MOD][song] * t[song][cur];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        std::cout << std::fixed << calc(k, q[i]) << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.precision(9);

    int c;
    std::cin >> c;
    while (c--)
    {
        memset(dp, 0, sizeof(dp));
        getinput();
        solve();
    }
}