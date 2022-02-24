#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
    string s, t;
    cin >> s >> t;

    for (i = 1; t[i - 1]; i++)
    {
        for (j = 1; s[j - 1]; j++)
        {
            if (s[j - 1] == t[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[i - 1][j - 1];
}