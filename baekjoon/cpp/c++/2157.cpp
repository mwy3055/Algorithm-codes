#include <bits/stdc++.h>

struct flight
{
    int desc, meal;
    flight(int d, int m) : desc(d), meal(m) {}
};

std::vector<flight> flights[301];
int n, m, k, dp[301][301];
/**
 * dp[i][j]: 현재 i번 도시에 있고 지금까지 j개의 도시를 거쳐 왔을 때,
 *           추가로 먹을 수 있는 기내식의 점수의 최댓값
 *           -1: 아직 계산되지 않음
 *           -2: 여기서 n번 도시에 도착할 수 없음
 */

int solve(int cur, int left)
{
    auto &ret = dp[cur][left];
    if (cur == n)
        return ret = 0;
    else if (left == m)
        return ret = -2;
    else if (ret != -1)
        return ret;

    bool all_unavailable = true;
    ret = 0;
    for (auto &f : flights[cur])
    {
        int rtn = solve(f.desc, left + 1);
        if (rtn != -2)
        {
            all_unavailable = false;
            ret = std::max(ret, rtn + f.meal);
        }
    }
    if (all_unavailable)
        ret = -2;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof(dp));

    std::cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a < b)
            flights[a].emplace_back(b, c);
    }

    int ans = solve(1, 1);
    std::cout << ans;
}