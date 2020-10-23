#include <bits/stdc++.h>

struct node
{
    int cur, count, speed;
    node(int cur, int count, int speed) : cur(cur), count(count), speed(speed) {}
};

struct cmp
{
    bool operator()(const node n1, const node n2)
    {
        if (n1.count != n2.count)
            return n1.count > n2.count;
        return n1.cur < n2.cur;
    }
};

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

    int ans = solve(1, 0);
    std::cout << solve(1, 0);
}