#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][2]; // 0: 먼저 하는 사람, 1: 나중에 하는 사람

int solve()
{
    int n;
    cin >> n;
    int card[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> card[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i][0] = card[i];
        dp[i][i][1] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][i + 1][0] = max(card[i], card[i + 1]);
        dp[i][i + 1][1] = min(card[i], card[i + 1]);
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            int case1 = card[i] + dp[i + 1][j][1], case2 = card[j] + dp[i][j - 1][1];
            if (case1 > case2)
            {
                dp[i][j][0] = case1;
                dp[i][j][1] = dp[i + 1][j][0];
            }
            else
            {
                dp[i][j][0] = case2;
                dp[i][j][1] = dp[i][j - 1][0];
            }
        }
    }

    return dp[1][n][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
}