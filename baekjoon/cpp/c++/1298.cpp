#include <bits/stdc++.h>

std::vector<int> graph[101];
std::vector<int> track(101);
std::vector<bool> visit(101);

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

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
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