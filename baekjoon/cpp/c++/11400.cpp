#include <bits/stdc++.h>

using vi = std::vector<int>;
using pii = std::pair<int, int>;
std::vector<vi> graph;
std::vector<pii> answers;

int order[100001], ord;

// A와 A의 자식 노드가 A에서 parent로 가는 간선을 사용하지 않고 도달할 수 있는 정점 중 가장 먼저 방문한 정점
int dfs(int cur, int parent)
{
    order[cur] = ++ord;
    int ret = order[cur];
    for (auto &adj : graph[cur])
    {
        if (adj == parent)
            continue;
        if (order[adj] == 0)
        {
            int low = dfs(adj, cur);
            if (low > order[cur])
            {
                answers.emplace_back(std::min(cur, adj), std::max(cur, adj));
            }
            ret = std::min(ret, low);
        }
        else
        {
            ret = std::min(ret, order[adj]);
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int v, e;
    std::cin >> v >> e;
    graph.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    std::sort(answers.begin(), answers.end());
    std::cout << answers.size() << '\n';
    for (auto &ans : answers)
        std::cout << ans.first << ' ' << ans.second << '\n';
}