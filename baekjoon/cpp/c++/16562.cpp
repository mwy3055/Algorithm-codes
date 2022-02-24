// SCC에서 친구비가 가장 작은 원소만 더한다?
#include <bits/stdc++.h>

using vi = std::vector<int>;
using pii = std::pair<int, int>;

int n, m, k, cost[10001];
vi graph[10001];
std::vector<vi> groups;
bool visit[10001];

void make_scc(int root)
{
    std::queue<int> q;
    vi group(0);

    q.push(root);
    visit[root] = true;
    group.push_back(cost[root]);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        for (auto &adj : graph[top])
        {
            if (!visit[adj])
            {
                q.push(adj);
                visit[adj] = true;
                group.push_back(cost[adj]);
            }
        }
    }
    groups.push_back(group);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> cost[i];
    for (int i = 0; i < m; i++)
    {
        int v, w;
        std::cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
            make_scc(i);
    }

    int ans = 0;
    for (auto &group : groups)
    {
        std::sort(group.begin(), group.end());
        ans += group.front();
    }
    if (ans > k)
        std::cout << "Oh no" << '\n';
    else
        std::cout << ans << '\n';
}