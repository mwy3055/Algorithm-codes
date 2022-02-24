#include <bits/stdc++.h>

using ll = long long;
using point = std::pair<ll, ll>;
using vp = std::vector<point>;
using vec = std::pair<int, int>;

bool isCCW(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
    return (by - ay) * (cx - ax) > (cy - ay) * (bx - ax);
}
bool isCCW(point a, point b, point c)
{
    return isCCW(a.first, a.second, b.first, b.second, c.first, c.second);
}

vp points;
bool comp(point &a, point &b) // sort points by CCW orientation
{
    ll aq = (a.first - points[0].first), ap = (a.second - points[0].second);
    ll bq = (b.first - points[0].first), bp = (b.second - points[0].second);
    if (aq * bp != ap * bq)
        return aq * bp < ap * bq;
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

void gethull(vp &hull)
{
    std::swap(points[0], *std::min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), comp); // sort points to CCW orientation

    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < points.size(); i++)
    {
        while (2 <= hull.size())
        {
            auto second = hull.back();
            hull.pop_back();
            auto first = hull.back();
            if (isCCW(first, second, points[i]))
            {
                hull.push_back(second);
                break;
            }
        }
        hull.push_back(points[i]);
    }
}

double dist(point &a, point &b)
{
    double dx = a.first - b.first, dy = a.second - b.second;
    return std::sqrt(dx * dx + dy * dy);
}

vec getvect(int i, vp &hull)
{
    return vec(hull[i + 1].first - hull[i].first, hull[i + 1].second - hull[i].second);
}

ll cross(vec i, vec j)
{
    return i.first * j.second - i.second - j.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    points.resize(c);
    for (auto &p : points)
        std::cin >> p.first >> p.second;

    vp hull;
    gethull(hull);

    double ans = 0;
    int a = 0, b = 0, n = hull.size();
    for (int i = 0, j = 1; i < n; i++)
    {
        int ni = (i + 1) % n;
        while (true)
        {
            int nj = (j + 1) % n;
            if (isCCW(0, 0,
                      hull[ni].first - hull[i].first, hull[ni].second - hull[i].second,
                      hull[nj].first - hull[j].first, hull[nj].second - hull[j].second))
                j = nj;
            else
                break;
        }
        double d = dist(hull[i], hull[j]);
        if (ans < d)
        {
            ans = d;
            a = i, b = j;
        }
    }
    std::cout.precision(9);
    std::cout << std::fixed << ans << '\n';
}