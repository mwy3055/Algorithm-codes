#include <bits/stdc++.h>

using vi = std::vector<int>;

std::vector<bool> visit;
std::vector<vi> graph;
vi possess, assigned;

void init(int &n, int &m)
{
    graph.resize(n + 1);
    visit.resize(m + 1);
    possess.resize(m + 1);
    assigned.resize(n + 1);
}

bool dfs(int cur)
{
    for (auto &task : graph[cur])
    {
        if (visit[task])
            continue;
        visit[task] = true;
        if (possess[task] == 0 || dfs(possess[task]))
        {
            possess[task] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    init(n, m);
    for (int i = 1; i <= n; i++)
    {
        int s;
        std::cin >> s;
        for (int j = 0; j < s; j++)
        {
            int num;
            std::cin >> num;
            graph[i].push_back(num);
        }
    }

    int ans = 0, left = k;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n && left > 0; i++)
        {
            std::fill(visit.begin(), visit.end(), false);
            if (dfs(i))
            {
                ans++;
                assigned[i]++;
            }
            if (assigned[i] == 2)
            {
                left--;
            }
        }
    }
    std::cout << ans << '\n';
}