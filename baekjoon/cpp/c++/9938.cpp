#include <bits/stdc++.h>

int n, l;
std::vector<int> graph[300001];
bool matched[300001];

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
    void merge(int a, int b) // a에 들어있는 술은 b에도 들어갈 수 있음
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        root[root1] = root2;
    }
};

UnionFind uf(300001);

void getinput()
{
    std::cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[i].push_back(a);
        graph[i].push_back(b);
    }
}

void solve()
{
    // parent[i]: i번 서랍의 술이 들어갈 수 있는 다른 위치
    // 술병이 움직이는 과정을 재귀적으로 계산 + 압축하기 위해 union find를 사용했다.
    for (int i = 1; i <= n; i++)
    {
        bool result;
        auto &a = graph[i][0], &b = graph[i][1];
        int pa, pb;
        if (!matched[a])
        {
            result = true;
            matched[a] = true;
            uf.merge(a, b); // 이 술은 b에도 들어갈 수 있음
        }
        else if (!matched[b])
        {
            result = true;
            matched[b] = true;
            uf.merge(b, a); // 이 술은 a에도 들어갈 수 있음
        }
        else if (!matched[(pa = uf.find(a))])
        {
            // pa: a에 들어있던 술이 이동한 위치
            result = true;
            matched[pa] = true;
            uf.merge(a, b);
        }
        else if (!matched[(pb = uf.find(b))])
        {
            // pb: b에 들어있던 술이 이동한 위치
            result = true;
            matched[pb] = true;
            uf.merge(b, a);
        }
        else
            result = false;
        std::cout << (result ? "LADICA" : "SMECE") << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}