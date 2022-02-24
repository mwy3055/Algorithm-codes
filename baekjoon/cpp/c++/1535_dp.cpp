#include <bits/stdc++.h>
using namespace std;

int n;
int hloss[20], hget[20];

void getinput()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hloss[i];
    for (int i = 0; i < n; i++)
        cin >> hget[i];
}
int solve()
{
    int dp[20][101]; //dp[i][j]: i번 사람에게 인사를 하거나 안 했고, 그떄의 체력이 j일 때 얻는 최대 기쁨
    memset(dp, -1, 20 * 101);

    dp[0][100] = 0;
    dp[0][100 - hloss[0]] = hget[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = dp[i - 1][j];
                if (0 < j - hloss[i])
                    dp[i][j - hloss[i]] = max(dp[i][j - hloss[i]], dp[i - 1][j] + hget[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
        ans = max(ans, dp[n - 1][i]);
    return ans;
}

int main()
{
    getinput();

    cout << solve();
}