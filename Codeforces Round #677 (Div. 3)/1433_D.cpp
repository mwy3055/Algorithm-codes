#include <bits/stdc++.h>

struct road
{
    int x, y;
    road(int x, int y) : x(x), y(y) {}
};

void solve(int &n, std::vector<int> &a, std::vector<road> &roads)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] != a[j])
                roads.emplace_back(i, j);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        std::vector<road> roads;
        solve(n, a, roads);
        if (roads.size() >= n - 1)
        {
            std::cout << "YES" << '\n';
            for (int i = 0; i < n - 1; i++)
                std::cout << roads[i].x + 1 << ' ' << roads[i].y + 1 << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}