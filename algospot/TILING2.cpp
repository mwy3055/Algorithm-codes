#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int dp[101];

void init()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 100; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}