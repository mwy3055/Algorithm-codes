#include <bits/stdc++.h>

struct query
{
    int x, n1, n2;
    query(int x, int n1 = 0, int n2 = 0) : x(x), n1(n1), n2(n2) {}
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

    // b를 a에 병합
    void merge(int a, int b)
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        root[root1] += root[root2];
        root[root2] = root1;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    /**
     * Union-Find
     * 그러나 이미 연결된 노드를 끊기는 어렵다.
     * 따라서 쿼리를 거꾸로 수행하자.
     * 맨 마지막 쿼리부터 수행하고, 간선이 하나도 없는 상태에서 하나씩 연결하자.
     */
    int n, q;
    std::cin >> n >> q;
    std::vector<int> parent(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int par;
        std::cin >> par;
        parent[i + 2] = par;
    }
    std::stack<query> s;
    for (int i = 0; i < (n - 1) + q; i++)
    {
        int x;
        std::cin >> x;
        if (x == 0)
        {
            int b;
            std::cin >> b;
            s.push(query(x, b));
        }
        else
        {
            int c, d;
            std::cin >> c >> d;
            s.push(query(x, c, d));
        }
    }

    UnionFind uf(n);
    std::stack<bool> ans;
    while (!s.empty())
    {
        auto top = s.top();
        s.pop();

        int x = top.x;
        if (x == 0)
        {
            int b = top.n1;
            uf.merge(parent[b], b);
        }
        else
        {
            int c = top.n1, d = top.n2;
            auto parent_c = uf.find(c), parent_d = uf.find(d);
            ans.push(parent_c == parent_d);
        }
    }

    while (!ans.empty())
    {
        auto top = ans.top();
        ans.pop();
        std::cout << (top ? "YES" : "NO")
                  << '\n';
    }
}