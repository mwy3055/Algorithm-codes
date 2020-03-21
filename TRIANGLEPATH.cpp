#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
int solve(int y, int x, int &n, vvi &arr, vvi &dp)
{
    if (y < x)
        return 0;
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    if (y == n - 1)
        return ret = arr[y][x];
    return ret = max(solve(y + 1, x, n, arr, dp), solve(y + 1, x + 1, n, arr, dp)) + arr[y][x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        vvi arr(n, vector<int>(n)), dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> arr[i][j];
        cout << solve(0, 0, n, arr, dp) << '\n';
    }
}