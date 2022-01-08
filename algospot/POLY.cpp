#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
const int MOD = 10000000;

int solve(int n, int first, vvi &dp)
{
    if (n == first)
        return 1;
    int &ret = dp[n][first];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int second = 1; second <= n - first; second++)
        ret = (ret + (second + first - 1) * solve(n - first, second, dp)) % MOD;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    vector<vector<int>> dp(101, vector<int>(101, -1));
    while (c--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + solve(n, i, dp)) % MOD;
        cout << ans << '\n';
    }
}