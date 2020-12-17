#include <bits/stdc++.h>

int map[301][301];
int dp[301][301];

bool isin(int y, int x, int &n, int &m)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

int solve(int r, int c, int &n, int &m)
{
    auto &ret = dp[r][c];
    if (ret != -1)
        return ret;
    if (r == n - 1 && c == m - 1)
        return ret = map[r][c];
    ret = 0;
    if (isin(r + 1, c, n, m))
        ret = std::max(ret, solve(r + 1, c, n, m));
    if (isin(r, c + 1, n, m))
        ret = std::max(ret, solve(r, c + 1, n, m));
    ret += map[r][c];
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    std::cout << solve(0, 0, n, m);
}