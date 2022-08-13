#include <bits/stdc++.h>

using point = std::pair<int, int>;
// ax + by + c = 0
struct line
{
    double a, b, c;
    line(double a, double b, double c) : a(a), b(b), c(c) {}
};

std::vector<point> points;

bool comp(point &a, point &b) // sort points by CCW orientation
{
    int aq = (a.first - points[0].first), ap = (a.second - points[0].second);
    int bq = (b.first - points[0].first), bp = (b.second - points[0].second);
    if (aq * bp != ap * bq)
        return aq * bp < ap * bq;
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
bool isCCW(point &a, point &b, point &c)
{
    return (b.second - a.second) * (c.first - a.first) > (b.first - a.first) * (c.second - a.second);
}

void getinput()
{
    points.clear();

    int n;
    std::cin >> n;
    if (n == 0)
    {
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }
}

std::vector<point> make_convex_hull()
{
    std::swap(points[0], *min_element(points.begin(), points.end()));
    std::sort(points.begin() + 1, points.end(), comp);

    std::stack<point> s;
    s.push(points[0]);
    s.push(points[1]);
    for (int i = 2; i < points.size(); i++)
    {
        while (s.size() >= 2)
        {
            auto second = s.top();
            s.pop();
            auto first = s.top();
            if (isCCW(first, second, points[i]))
            {
                s.push(second);
                break;
            }
        }
        s.push(points[i]);
    }

    std::vector<point> convex_hull;
    while (!s.empty())
    {
        convex_hull.push_back(s.top());
        s.pop();
    }
    std::reverse(convex_hull.begin(), convex_hull.end());
    return convex_hull;
}

line make_line(point &a, point &b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return line(dy, -dx, dx * a.second - dy * a.first);
}

double dist(line l, point p)
{
    return std::abs(l.a * p.first + l.b * p.second + l.c) / std::sqrt(l.a * l.a + l.b * l.b);
}

double solve()
{
    // 볼록 다각형으로 변환 (오목 다각형을 만드는 점은 고려하지 않음)
    auto actual_points = make_convex_hull();
    // 각 변에서 가장 먼 점을 찾는다.
    auto ans = 1e9;
    for (int i = 0; i < actual_points.size(); i++)
    {
        auto &cur = actual_points[i];
        auto &next = actual_points[(i + 1) % actual_points.size()];
        auto l = make_line(cur, next);
        auto temp_ans = 0.0;
        for (auto &p : actual_points)
        {
            temp_ans = std::max(temp_ans, dist(l, p));
        }
        ans = std::min(ans, temp_ans);
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout.precision(2);
    std::cout << std::fixed;

    int testcase = 1;
    while (true)
    {
        getinput();
        auto ans = solve();
        // TODO: 0.01의 배수?
        std::cout << "Case " << testcase << ": " << std::ceil(ans * 100) / 100 << '\n';
        testcase++;
    }
}