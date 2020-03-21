#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

bool isin(int y, int x, int n)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool dfs(int y, int x, int &n, vector<vector<int>> &arr)
{
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    if (y == n - 1 && x == n - 1)
        return ret = true;
    ret = false;
    if (isin(y + arr[y][x], x, n))
        ret |= dfs(y + arr[y][x], x, n, arr);
    if (isin(y, x + arr[y][x], n))
        ret |= dfs(y, x + arr[y][x], n, arr);
    return ret;
}
void init()
{
    for (int i = 0; i < 100; i++)
        memset(dp + i, -1, sizeof(int) * 100);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        init();
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        cout << (dfs(0, 0, n, arr) ? "YES" : "NO") << '\n';
    }
}