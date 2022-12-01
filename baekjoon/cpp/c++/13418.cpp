#include <bits/stdc++.h>

struct edge
{
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
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
    void clear()
    {
        std::fill(root.begin(), root.end(), -1);
    }
};

int n, m;
std::vector<edge> edges;

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m + 1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
}

int MST()
{
    UnionFind uf(n);
    int count = 0, cost = 0;
    for (auto &[a, b, c] : edges)
    {
        if (uf.find(a) != uf.find(b))
        {
            uf.merge(a, b);
            cost += c;
            count++;
        }
        if (count == n)
            break;
    }
    return cost;
}

int solve()
{
    auto cmp = [](const edge &a, const edge &b)
    { return a.c < b.c; };
    // 최댓값
    // 처음에는 1: 내리막길, 0: 오르막길
    // 노드가 N+1개: 간선은 N개
    // 오르막길의 수 = N - (내리막길의 수)
    std::sort(edges.begin(), edges.end(), cmp);
    int downhill = MST();
    int uphill = n - downhill;
    int max = uphill * uphill;

    // 최솟값
    // 가중치 바꿔주고 MST
    for (auto &[a, b, c] : edges)
    {
        c = 1 - c;
    }
    std::sort(edges.begin(), edges.end(), cmp);
    uphill = MST();
    int min = uphill * uphill;

    return max - min;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}