#include <bits/stdc++.h>

struct road
{
    int x, y;
    road(int x, int y) : x(x), y(y) {}
};

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
        int diff = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[0] != a[i])
            {
                diff = i;
                roads.emplace_back(0, i);
            }
        }
        if (diff == -1)
        {
            std::cout << "NO" << '\n';
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            if (a[0] == a[i])
            {
                roads.emplace_back(i, diff);
            }
        }

        std::cout << "YES" << '\n';
        for (int i = 0; i < n - 1; i++)
            std::cout << roads[i].x + 1 << ' ' << roads[i].y + 1 << '\n';
    }
}