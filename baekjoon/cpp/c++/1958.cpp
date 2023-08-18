#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];
string s, t, w;

int solve()
{
    int i, j, k;
    for (i = 1; s[i - 1]; i++)
    {
        for (j = 1; t[j - 1]; j++)
        {
            for (k = 1; w[k - 1]; k++)
            {
                if (s[i - 1] == t[j - 1] && t[j - 1] == w[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i][j - 1][k], dp[i - 1][j][k]));
            }
        }
    }

    return dp[i - 1][j - 1][k - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t >> w;
    cout << solve();
}