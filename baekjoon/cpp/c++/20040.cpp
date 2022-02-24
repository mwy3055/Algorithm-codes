#include <bits/stdc++.h>

const int MAX = 500000;

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

bool union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return true;

    if (root[root1] > root[root2])
        std::swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();

    int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
            std::swap(a, b);
        if (union_vertex(a, b))
        {
            ans = i + 1;
            break;
        }
    }
    std::cout << ans << '\n';
}