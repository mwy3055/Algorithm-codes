#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, ll>; // dest가 cost만큼 가볍다
int n, m;
ll dw[100001]; // dw[i]: 루트보다 얼마나 무거운가?

class UnionFind
{
private:
    int size;
    std::vector<int> root;

public:
    UnionFind(int size) : size(size)
    {
        root.resize(size + 1);
        for (int i = 0; i <= size; i++)
        {
            root[i] = i;
        }
    }
    // 재귀 업데이트: 잘 알아두기
    int find(int n)
    {
        if (root[n] == n)
            return n;
        auto parent = find(root[n]);
        dw[n] += dw[root[n]];
        return root[n] = parent;
    }
    void merge(int a, int b, int w)
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        // merge weight
        dw[root2] = dw[a] + w - dw[b];
        root[root2] = root1;
    }
};

void init()
{
    std::memset(dw, 0, sizeof(dw));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (true)
    {
        std::cin >> n >> m;
        if (n == 0 && m == 0)
            exit(0);

        init();

        UnionFind uf(n);
        char c;
        while (m--)
        {
            std::cin >> c;
            if (c == '!')
            {
                int a, b, w;
                std::cin >> a >> b >> w; // 무거운 게 루트
                uf.merge(a, b, w);
            }
            else if (c == '?')
            {
                int a, b;
                std::cin >> a >> b;
                auto pa = uf.find(a), pb = uf.find(b);
                if (pa == pb)
                {
                    std::cout << dw[b] - dw[a] << '\n';
                }
                else
                {
                    std::cout << "UNKNOWN" << '\n';
                }
            }
            else
                exit(-1);
        }
    }
}