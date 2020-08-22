#include <bits/stdc++.h>

using ll = long long;
struct edge
{
    int s, e, cost;
    edge(int s, int e, int cost) : s(s), e(e), cost(cost) {}
    bool operator==(edge e)
    {
        return this->s == e.s && this->e == e.e && this->cost == e.cost;
    }
    bool operator<(edge e)
    {
        return this->cost < e.cost;
    }
};
ll n, m, k;
std::vector<edge> graph[1000001], total_graph;

const int MAX = 1000010;
int root[MAX + 1];
void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}

int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}

void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        std::swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

ll kruskal()
{
    std::sort(total_graph.begin(), total_graph.end());
    bool isl_added = false;
    ll added = 0, costsum = 0;
    for (auto &e : total_graph)
    {
        if (find(e.s) == find(e.e))
            continue;
        union_vertex(e.s, e.e);
        if (e.s == 0 || e.e == 0)
            isl_added = true;
        costsum += e.cost;
        added++;
        if (added == (isl_added ? n : n - 1))
            break;
    }
    return costsum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int si;
        std::cin >> si;
        graph[0].emplace_back(0, i, si);
        graph[i].emplace_back(i, i % n + 1, 0);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        if (b == n && a == 1)
            std::swap(a, b);
        graph[a].pop_back();
    }
    for (int i = 0; i <= n; i++)
    {
        for (auto &e : graph[i])
            total_graph.push_back(e);
    }

    ll mincost = kruskal();
    std::cout << (mincost <= k ? "YES" : "NO");
}