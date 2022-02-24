#include <bits/stdc++.h>

int n, m, v[10][100000], dp[100000][10][2];

// i번째 날에 j번 디저트를 먹을 때, N번째 날까지 얻을 수 있는 만족도의 최댓값.
// same: (i-1)번째 날에도 j번 디저트를 먹었는가?
int search(int i, int j, bool same)
{
    if (i == n)
        return 0;
    auto &ret = dp[i][j][same];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int eat = 0; eat < m; eat++)
    {
        int tans = search(i + 1, eat, j == eat);
        ret = std::max(ret, tans);
    }
    ret += (same ? v[j][i] / 2 : v[j][i]);
    return ret;
}

int solve()
{
    int ans = 0;
    for (int j = 0; j < m; j++)
        ans = std::max(ans, search(0, j, false));
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            std::cin >> v[i][j];

    std::cout << solve();
}