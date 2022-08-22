#include <bits/stdc++.h>

using ll = long long;
using pll = std::pair<ll, ll>;

int n, m;
std::vector<int> tree[100001];
ll praise[100001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int parent;
        std::cin >> parent;
        if (parent != -1)
            tree[parent].push_back(i);
    }
    for (int j = 0; j < m; j++)
    {
        int i, w;
        std::cin >> i >> w;
        praise[i] += w;
    }
}

void solve()
{
    std::queue<pll> q; // number, praise
    q.emplace(1, 0);
    while (!q.empty())
    {
        auto [num, pr] = q.front();
        q.pop();
        praise[num] = pr;
        for (auto &child : tree[num])
        {
            q.emplace(child, pr + praise[child]);
        }
    }

    for (int i = 1; i <= n; i++)
        std::cout << praise[i] << ' ';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}