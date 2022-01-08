#include <bits/stdc++.h>

const int INF = 1 << 30;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const point p)
    {
        return (this->x == p.x) && (this->y == p.y);
    }
};

// 점 a와 b 사이의 거리
int get_dist_sq(point &a, point &b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::vector<point> points;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }

    // 주어진 점들 중 하나가 답이다.
    // 수직이등분선 그을 필요 없다.
    int min_sum = INF;
    point answer;
    for (auto &p : points)
    {
        int farthest = 0;
        for (auto &other : points)
        {
            farthest = std::max(farthest, get_dist_sq(p, other));
        }
        if (farthest < min_sum)
        {
            answer = p;
            min_sum = farthest;
        }
    }
    std::cout << answer.x << ' ' << answer.y;
}