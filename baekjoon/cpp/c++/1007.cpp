#include <bits/stdc++.h>

struct point
{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
};

struct vector
{
    int dx, dy;
    vector(int dx, int dy) : dx(dx), dy(dy) {}
};

double choose(int idx, int left, std::vector<point> &points, std::vector<bool> &select)
{
    if (left == 0)
    {
        double posx = 0, posy = 0;
        double negx = 0, negy = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (select[i])
            {
                posx += points[i].x;
                posy += points[i].y;
            }
            else
            {
                negx += points[i].x;
                negy += points[i].y;
            }
        }
        double dx = posx - negx, dy = posy - negy;
        return dx * dx + dy * dy;
    }
    double ans = (long long)1 << 48;
    select[idx] = true;
    ans = choose(idx + 1, left - 1, points, select);
    select[idx] = false;
    if (idx < points.size() - left)
        ans = std::min(ans, choose(idx + 1, left, points, select));
    return ans;
}

double solve(int &n, std::vector<point> &points)
{
    std::vector<bool> select(n, false);
    return choose(0, n / 2, points, select);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    std::cout.precision(8);
    std::cout << std::fixed;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<point> points;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            std::cin >> x >> y;
            points.emplace_back(x, y);
        }
        std::cout << std::sqrt(solve(n, points)) << '\n';
    }
}