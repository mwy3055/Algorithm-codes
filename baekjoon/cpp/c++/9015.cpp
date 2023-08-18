#include <bits/stdc++.h>

struct point
{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point add(int dx, int dy)
    {
        return point(x + dx, y + dy);
    }

    int dist(point &other)
    {
        int dx = x - other.x;
        int dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

int n;
std::vector<point> points;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }
}

bool compare(point p1, point p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int solve()
{
    std::sort(points.begin(), points.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto &p1 = points[i];
        for (int j = i + 1; j < n; j++)
        {
            auto &p2 = points[j];
            // find other points
            auto dx = p2.x - p1.x, dy = p2.y - p1.y;
            auto p3 = p1.add(-dy, dx), p4 = p2.add(-dy, dx);
            if (std::binary_search(points.begin(), points.end(), p3, compare) &&
                std::binary_search(points.begin(), points.end(), p4, compare))
            {
                ans = std::max(ans, p1.dist(p2));
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        getinput();
        std::cout << solve() << '\n';
        points.clear();
    }
}