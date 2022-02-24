#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i * i <= 50000; i++)
    {
        dp[i * i] = 1;
        for (int j = i; i * i + j * j <= 50000; j++)
        {
            dp[i * i + j * j] = 2;
        }
    }

    int n;
    cin >> n;
    if (dp[n] == 1 || dp[n] == 2)
    {
        cout << dp[n];
        return 0;
    }
    for (int i = 1; i * i <= n; i++)
    {
        if (dp[n - i * i] == 2)
        {
            cout << 3;
            return 0;
        }
    }
    cout << 4;
}