#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
int preprocess(int y, int x, int &n, vvi &arr, vvi &val)
{
    if (y < x)
        return 0;
    int &ret = val[y][x];
    if (ret != -1)
        return ret;
    if (y == n - 1)
        return ret = arr[y][x];
    return ret = max(preprocess(y + 1, x, n, arr, val), preprocess(y + 1, x + 1, n, arr, val)) + arr[y][x];
}
int solve(int y, int x, int &n, vvi &val, vvi &dp)
{
    if (y == n - 1)
        return 1;
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    if (val[y + 1][x] > val[y + 1][x + 1])
        ret = solve(y + 1, x, n, val, dp);
    else if (val[y + 1][x] < val[y + 1][x + 1])
        ret = solve(y + 1, x + 1, n, val, dp);
    else
        ret = solve(y + 1, x, n, val, dp) + solve(y + 1, x + 1, n, val, dp);
    return ret;
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
        vvi arr(n, vector<int>(n)), val(n, vector<int>(n, -1)), dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> arr[i][j];
        int mval = preprocess(0, 0, n, arr, val);
        cout << solve(0, 0, n, val, dp) << '\n';
    }
}