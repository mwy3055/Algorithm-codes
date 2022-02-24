#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[301];
vi track(301);
std::vector<bool> visit(301);

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

    int n, m, k1, k2;
    std::cin >> n >> m >> k1 >> k2;
    for (int a = 0; a < k1; a++)
    {
        int i, j;
        std::cin >> i >> j;
        graph[i].push_back(j);
    }
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans1++;
    }

    for (int i = 1; i <= n; i++)
        graph[i].clear();
    for (int a = 0; a < k2; a++)
    {
        int i, j;
        std::cin >> i >> j;
        graph[i].push_back(j);
    }
    std::fill(track.begin(), track.end(), 0);
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans2++;
    }

    // conflict between korean and utf-8, so replace the korean string literal with english one
    std::cout << (ans1 < ans2 ? "heal" : "stop") << '\n';
}