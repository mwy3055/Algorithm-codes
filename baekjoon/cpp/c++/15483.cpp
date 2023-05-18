#include <bits/stdc++.h>

std::string a, b;
int dp[1001][1001];

void getinput()
{
    std::cin >> a >> b;
}

int solve()
{
    int n = a.length(), m = b.length();

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }
    return dp[n][m];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}