#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[201];
vi track(201);
std::vector<bool> visit(201);

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
        int u, v;
        std::cin >> u >> v;
        if (u % 2 != v % 2)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    int paired = 0;
    for (int i = 1; i <= n; i += 2)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            paired += 2;
    }
    if (paired < n)
        paired++;
    std::cout << paired << '\n';
}