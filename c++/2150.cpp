#include <bits/stdc++.h>

int nth[10001], visit[10001]; // 0: never visited, 1: currently searching, 2: search complete
std::stack<int> s;
std::vector<std::vector<int>> graph, scc;

struct cmp
{
    bool operator()(std::vector<int> &a, std::vector<int> &b) const
    {
        return a.front() < b.front();
    }
};

int dfs(int cur)
{
    static int nthval = 1;
    nth[cur] = nthval++;
    visit[cur] = 1;
    s.push(cur);

    int parent = nth[cur];
    for (auto &adj : graph[cur])
    {
        if (visit[adj] == 0)
        {
            parent = std::min(parent, dfs(adj));
        }
        else if (visit[adj] == 1)
        {
            parent = std::min(parent, nth[adj]);
        }
    }

    if (parent == nth[cur])
    {
        scc.emplace_back();
        auto &v = scc.back();
        int top = 0;
        while (!s.empty() && top != cur)
        {
            top = s.top();
            s.pop();
            visit[top] = 2;
            v.push_back(top);
        }
        std::sort(v.begin(), v.end());
    }
    return parent;
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
    }

    for (int i = 1; i <= v; i++)
    {
        if (visit[i] == 0)
            dfs(i);
    }

    std::sort(scc.begin(), scc.end(), cmp());
    std::cout << scc.size() << '\n';
    for (auto &s : scc)
    {
        for (auto &node : s)
            std::cout << node << ' ';
        std::cout << -1 << '\n';
    }
}