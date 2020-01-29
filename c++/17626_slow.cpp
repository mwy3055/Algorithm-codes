#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int solve(int n, int depth)
{
    if (dp[n] < 5)
        return dp[n];
    if (3 < depth)
        return 4;
    int bound = (int)(sqrt(n) + 0.5), ans = 4;
    for (int i = bound; i >= 1; i--)
    {
        if (n - i * i >= 0)
        {
            ans = min(ans, 1 + solve(n - i * i, depth + 1));
        }
        if (ans <= 2)
            break;
    }

    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= 50000; i++)
        dp[i] = 5;
    dp[0] = 0, dp[1] = 1;

    int n;
    cin >> n;
    cout << solve(n, 0) << '\n';
    //cout << dp[n] << '\n';
}