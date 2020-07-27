#include <bits/stdc++.h>

using vi = std::vector<int>;
std::vector<vi> tree(1025, vi(1025, 0));
int n;

int sum(int x, int y) // (1, 1) ~ (x, y)
{
    int ret = 0;
    while (x > 0)
    {
        int ty = y;
        while (ty > 0)
        {
            ret += tree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return ret;
}
int getsum(int x1, int y1, int x2, int y2)
{
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}
void update(int x, int y, int diff)
{
    while (x <= n)
    {
        int ty = y;
        while (ty <= n)
        {
            tree[x][ty] += diff;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            std::cin >> num;
            update(i, j, num);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int w;
        std::cin >> w;
        if (w == 0)
        {
            int x, y, c, target;
            std::cin >> x >> y >> c;
            update(x, y, c - getsum(x, y, x, y));
        }
        else
        {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << getsum(x1, y1, x2, y2) << '\n';
        }
    }
}