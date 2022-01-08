#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[201], track(201);
std::vector<bool> visit(201);

bool canattach(int &w, int &calla)
{
    if (2 * w <= 4 * calla && 4 * calla <= 3 * w)
        return true;
    else if (4 * w <= 4 * calla && 4 * calla <= 5 * w)
        return true;
    else
        return false;
}

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
    vi shirts(n), callas(m);
    for (auto &s : shirts)
        std::cin >> s;
    for (auto &c : callas)
        std::cin >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (canattach(shirts[i], callas[j]))
            {
                graph[i + 1].push_back(j + 1);
            }
        }
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