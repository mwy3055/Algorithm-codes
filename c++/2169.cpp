#include <bits/stdc++.h>
using namespace std;

const int INF = -2e9;
int n, m, arr[1000][1000], dp[1000][1000][3];

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = INF;

    dp[n - 1][m - 1][0] = arr[n - 1][m - 1];
    dp[n - 1][m - 1][2] = arr[n - 1][m - 1];
    for (int j = m - 2; j >= 0; j--)
    {
        dp[n - 1][j][2] = dp[n - 1][j + 1][2] + arr[n - 1][j];
        dp[n - 1][j][0] = dp[n - 1][j + 1][0] + arr[n - 1][j];
    }
}
bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
int solve(int y, int x, int type) // 0: from left, 1: from right, 2: from up
{
    int &ret = dp[y][x][type];
    if (ret != INF)
        return ret;

    if (type != 1 && isin(y, x + 1))
        ret = max(ret, solve(y, x + 1, 0));
    if (y != n - 1 && type != 0 && isin(y, x - 1))
        ret = max(ret, solve(y, x - 1, 1));
    if (isin(y + 1, x))
        ret = max(ret, solve(y + 1, x, 2));
    ret += arr[y][x];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    init();
    cout << solve(0, 0, 0);
}