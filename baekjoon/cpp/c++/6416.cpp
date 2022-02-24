#include <bits/stdc++.h>

using vi = std::vector<int>;

struct edge
{
    int u, v;
    edge(int u, int v) : u(u), v(v) {}
};

int search(int cur, std::vector<vi> &graph, std::vector<bool> &visit)
{
    int rtn = 1;
    visit[cur] = true;
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            return -1;
        rtn += search(adj, graph, visit);
    }
    return rtn;
}

bool solve(std::vector<edge> &edges)
{
    if (edges.empty())
        return true;
    std::vector<vi> graph(14);
    vi indegree(14, 0);
    std::vector<bool> exists(14, false);
    for (auto &e : edges)
    {
        graph[e.u].push_back(e.v);
        exists[e.u] = exists[e.v] = true;
        indegree[e.v]++;
    }

    int count = 0, deg_0 = 0, deg_1 = 0, root;
    for (int i = 1; i <= 14; i++)
    {
        if (!exists[i])
            continue;
        count++;
        if (indegree[i] == 0)
        {
            deg_0++;
            root = i;
        }
        else if (indegree[i] == 1)
            deg_1++;
    }
    if (!((deg_0 == 1) && (deg_0 + deg_1 == count)))
        return false;

    std::vector<bool> visit(14, false);
    int can_go = search(root, graph, visit);
    return can_go == count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int k = 1;
    while (true)
    {
        std::vector<edge> v;
        int a, b;
        std::cin >> a >> b;
        if (a < 0 && b < 0)
            break;
        while (a != 0 && b != 0)
        {
            v.emplace_back(a, b);
            std::cin >> a >> b;
        }
        auto ans = solve(v);
        if (ans)
            std::cout << "Case " << k << " is a tree." << '\n';
        else
            std::cout << "Case " << k << " is not a tree." << '\n';
        k++;
    }
}