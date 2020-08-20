#include <bits/stdc++.h>

std::vector<int> graph[1001], track(1001);
std::vector<bool> visit(1001);

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

int match(int &n, int k)
{
    int rtn = 0;
    for (int i = 1; i <= n && rtn < k; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
        {
            std::cout << "match: " << i << '\n';
            rtn++;
        }
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int p;
        std::cin >> p;
        for (int j = 0; j < p; j++)
        {
            int w;
            std::cin >> w;
            graph[i].push_back(w);
        }
    }

    int ans = match(n, n), matched = 0;
    while ((matched = match(n, k)) && ans < n + k)
    {
        ans = std::min(n + k, ans + matched);
        k -= matched;
    }
    std::cout << ans << '\n';
}