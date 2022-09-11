#include <bits/stdc++.h>

struct point
{
    int index, x, y;
    point(int index, int x, int y) : index(index), x(x), y(y) {}
    bool operator<(point other)
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
    int dist(point other)
    {
        auto dx = x - other.x, dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

int n;
std::vector<point> points;

// ccw > 0: counterclockwise
// ccw < 0: clockwise
// ccw = 0: parallel
int ccw(point x, point y, point z) // (x, y)
{
    int v1x = y.x - x.x, v1y = y.y - x.y;
    int v2x = z.x - y.x, v2y = z.y - y.y;
    int cross = v1x * v2y - v1y * v2x; // overflow!!
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}

void getinput()
{
    points.clear();

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(i, x, y);
    }
}

void solve()
{
    // 좌표가 가장 작은 점을 찾는다.
    std::swap(points[0], *min_element(points.begin(), points.end()));
    // CCW로 정렬한다.
    // 0번 점과의 각도가 작은 순서대로 정렬된다.
    std::sort(points.begin() + 1, points.end(), [](point &a, point &b)
              {
        if(ccw(points[0], a, b)) return ccw(points[0], a, b)>0;
        return a.dist(points[0])<b.dist(points[0]); });
    // 예외: 0번 점과 마지막 점을 잇는 직선 위의 점들은
    // 거리가 먼 점부터 출력해야 한다.
    int index = n - 1;
    while (ccw(points[0], points[index - 1], points[index]) == 0)
        index--;
    std::reverse(points.begin() + index, points.end());

    for (auto &p : points)
        std::cout << p.index << ' ';
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        getinput();
        solve();
    }
}