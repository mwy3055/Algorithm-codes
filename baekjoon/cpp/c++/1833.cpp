#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using edge = std::pair<int, pii>;

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
UnionFind uf(250);

int n;
std::vector<edge> inputs;
std::vector<pii> ans_nodes;
int total_cost, new_rail;

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost;
            std::cin >> cost;
            if (i < j && cost < 0)
            {
                total_cost += -cost;
                uf.merge(i, j);
            }
            else if (cost > 0)
            {
                inputs.emplace_back(cost, pii(i, j));
            }
        }
    }
}

void solve()
{
    std::sort(inputs.begin(), inputs.end());
    for (auto &[cost, nodes] : inputs)
    {
        if (uf.find(1) == -n)
            break;
        auto &[i, j] = nodes;
        if (uf.find(i) != uf.find(j))
        {
            ans_nodes.push_back(nodes);
            total_cost += cost;
            uf.merge(i, j);
        }
    }

    std::cout << total_cost << ' ' << ans_nodes.size() << '\n';
    for (auto &[i, j] : ans_nodes)
    {
        std::cout << i << ' ' << j << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}