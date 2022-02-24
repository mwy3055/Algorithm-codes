#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000003;
int n, k, dp[1001][1001][2][2];
bool select0;

int solve(int i, int j, bool sel) // (i-1)th color: sel, now looking i-th color, should select j colors
{
    if (j == 0)
        return (i < n ? dp[i][j][false][select0] = 1 : 1);
    if (i >= n)
        return 0;
    auto &ret = dp[i][j][sel][select0];
    if (n - i < j)
        return ret = 0;
    if (ret != -1)
        return ret;

    ret = 0;
    ret = (ret + solve(i + 1, j, false)) % MOD;
    if (i == 0 || (i > 0 && !sel))
    {
        if (i != n - 1 || (i == n - 1 && !select0))
        {
            if (i == 0)
                select0 = true;
            ret = (ret + solve(i + 1, j - 1, true)) % MOD;
            if (i == 0)
                select0 = false;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 2; k++)
                memset(dp[i][j][k], -1, sizeof(int) * 2);
        }
    }

    cin >> n >> k;
    cout << solve(0, k, false) << '\n';
}