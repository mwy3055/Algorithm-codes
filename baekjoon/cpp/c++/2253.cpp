#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
bool small[10001];
int n, m, dp[10001][1001];

// dp[i][j]: count needed to go to n, from i-th rock with speed j
int solve(int cur, int speed)
{
    auto &ret = dp[cur][speed];
    if (cur == n)
        return ret = 0;
    if (ret != INF)
        return ret;
    for (int x = std::max(1, speed - 1); x <= speed + 1; x++)
    {
        int next = cur + x;
        if (next <= n && !small[next])
        {
            auto result = solve(next, x);
            if (result != -1)
                ret = std::min(ret, result + 1);
        }
    }
    if (ret == INF)
        ret = -1;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        small[x] = true;
    }

    std::cout << solve(1, 0);
}