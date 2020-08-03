#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[1001], track(1001);
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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::map<std::string, int> hashmap;
    for (int i = 1; i <= m; i++)
    {
        std::string name;
        std::cin >> name;
        hashmap[name] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        std::cin >> k;
        while (k--)
        {
            std::string name;
            std::cin >> name;
            graph[i].push_back(hashmap[name]);
        }
    }

    int match = 0;
    for (int i = 1; i <= n; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            match++;
    }
    if (match == n)
        std::cout << "YES" << '\n';
    else
        std::cout << "NO" << '\n'
                  << match << '\n';
}