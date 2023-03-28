#include <bits/stdc++.h>

using dest = std::pair<int, int>;  // node1, node2
using edge = std::pair<int, dest>; // cost, dest
using mst_edge = std::pair<int, int>;

const int MAX = 1000000;
int n, m, s, e;
std::vector<edge> edges;
std::vector<mst_edge> mst[100001];
bool visit[100001];

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

void getinput()
{
    std::cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++)
    {
        int h1, h2, k;
        std::cin >> h1 >> h2 >> k;
        edges.emplace_back(k, dest(h1, h2));
    }
}

void make_mst()
{
    for (auto &e : edges)
    {
        e.first = MAX - e.first;
    }
    std::sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int edge_count = 0;
    for (auto &e : edges)
    {
        auto &limit = e.first;
        auto &[h1, h2] = e.second;

        if (uf.find(h1) == uf.find(h2))
            continue;
        uf.merge(h1, h2);
        mst[h1].emplace_back(MAX - limit, h2);
        mst[h2].emplace_back(MAX - limit, h1);
        if (++edge_count == n - 1)
            break;
    }
}

int search(int cur, int weight)
{
    if (cur == e)
        return weight;

    visit[cur] = true;
    int max_weight = 0;
    for (auto &[limit, dest] : mst[cur])
    {
        if (!visit[dest])
        {
            int new_weight = std::min(weight, limit);
            max_weight = std::max(max_weight, search(dest, new_weight));
        }
    }
    return max_weight;
}

int solve()
{
    make_mst();
    return search(s, MAX);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}