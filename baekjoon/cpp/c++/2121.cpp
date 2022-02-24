#include <bits/stdc++.h>

using point = std::pair<int, int>;
std::vector<point> points;

bool exist(point a)
{
    return std::binary_search(points.begin(), points.end(), a);
}

bool exists(point a, point b, point c, point d)
{
    return exist(a) && exist(b) && exist(c) && exist(d);
}

int count(point &p, int &a, int &b)
{
    static int dx[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, -1, -1, 0, 0, 0, -1, -1}, dy[] = {0, 0, 1, 1, 0, 0, -1, -1, 0, 0, -1, -1, 0, 1, 1, 0};
    int rtn = 0, x = p.first, y = p.second;
    for (int i = 0; i < 4; i++)
    {
        if (exists(point(x + a * dx[i * 4], y + b * dy[i * 4]),
                   point(x + a * dx[i * 4 + 1], y + b * dy[i * 4 + 1]),
                   point(x + a * dx[i * 4 + 2], y + b * dy[i * 4 + 2]),
                   point(x + a * dx[i * 4 + 3], y + b * dy[i * 4 + 3])))
        {
            rtn++;
        }
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, a, b;
    std::cin >> n >> a >> b;
    points.resize(n);
    for (auto &p : points)
        std::cin >> p.first >> p.second;
    std::sort(points.begin(), points.end());

    long long ans = 0;
    for (auto &p : points)
    {
        ans += count(p, a, b);
    }
    std::cout << ans / 4 << '\n';
}