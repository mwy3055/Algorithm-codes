#include <bits/stdc++.h>
using namespace std;

int n, lcard[2001], rcard[2001], dp[2002][2002];
void getinput()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> lcard[i];
    for (int i = 1; i <= n; i++)
        cin >> rcard[i];
}

int solve()
{
    if (lcard[n] > rcard[n])
        dp[n][n] = rcard[n];

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i == n && j == n)
                continue;
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
            if (lcard[i] > rcard[j])
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + rcard[j]);
        }
    }

    return dp[1][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();
    cout << solve();
}