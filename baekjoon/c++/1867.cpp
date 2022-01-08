#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[501], track(501);
std::vector<bool> visit(501, false);

bool dfs(int cur)
{
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == 0 || dfs(track[adj]))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        std::cin >> r >> c;
        graph[r].push_back(c);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
}