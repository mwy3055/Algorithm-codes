#include <bits/stdc++.h>

using vi = std::vector<int>;

std::vector<bool> visit;
std::vector<vi> graph;
vi possess;

// true if matching succeeded
bool dfs(int cur)
{
    for (auto &room : graph[cur])
    {
        if (visit[room])
            continue;
        visit[room] = true;
        if (possess[room] == 0 || dfs(possess[room]))
        {
            possess[room] = cur;
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
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int si;
        std::cin >> si;
        for (int j = 0; j < si; j++)
        {
            int num;
            std::cin >> num;
            graph[i].push_back(num);
        }
    }

    int ans = 0;
    visit.resize(m + 1);
    possess.resize(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
}