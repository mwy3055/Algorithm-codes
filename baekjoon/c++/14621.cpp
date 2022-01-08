#include <bits/stdc++.h>

struct edge
{
    int cost, node1, node2;
    edge(int cost, int n1, int n2) : cost(cost), node1(n1), node2(n2) {}
    bool operator<(const edge &e)
    {
        return cost < e.cost;
    }
};

class UnionFind
{
private:
    int size;
    std::vector<int> root;

public:
    UnionFind(int size) : size(size)
    {
        root.resize(size + 1, -1);
    }
    int find(int n)
    {
        if (root[n] < 0)
            return n;
        return root[n] = find(root[n]);
    }
    void merge(int a, int b)
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        if (root1 > root2)
            std::swap(root1, root2);
        root[root1] += root[root2];
        root[root2] = root1;
    }
};

int n, m;
std::vector<edge> edges;
bool man[1001]; // 1-indexed

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char univ;
        std::cin >> univ;
        man[i] = (univ == 'M');
    }
    // 남초-남초 또는 여초-여초를 연결하는 간선은 버림
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        std::cin >> u >> v >> d;
        if (man[u] != man[v])
        {
            edges.emplace_back(d, u, v);
        }
    }
}

int solve()
{
    auto uf = UnionFind(n);
    int merged = 0, sum = 0;

    // 최소 스패닝 트리
    std::sort(edges.begin(), edges.end());
    for (auto &[cost, u, v] : edges)
    {
        if (uf.find(u) == uf.find(v))
            continue;

        uf.merge(u, v);
        sum += cost;
        merged++;
        if (merged == n - 1)
            break;
    }
    return (merged == n - 1) ? sum : -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}