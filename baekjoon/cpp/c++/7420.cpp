#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point
{
    ll y, x;
    Point(ll y, ll x) : y(y), x(x) {}
    bool operator<(const Point &a)
    {
        if (this->y == a.y)
            return this->x < a.x;
        return this->y < a.y;
    }
    bool operator==(const Point &a)
    {
        return this->y == a.y && this->x == a.x;
    }
};

const double PI = 3.1415926535;
int n, l;
vector<Point> points, result;
stack<Point> s;
bool comp(Point &a, Point &b) // sort points by CCW orientation
{
    ll aq = (a.y - points[0].y), ap = (a.x - points[0].x);
    ll bq = (b.y - points[0].y), bp = (b.x - points[0].x);
    if (aq * bp != ap * bq)
        return aq * bp < ap * bq;
    return a < b;
}
bool isCCW(Point &a, Point &b, Point &c)
{
    return (b.x - a.x) * (c.y - a.y) >= (b.y - a.y) * (c.x - a.x);
}
void convexHull()
{
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), comp);

    for (auto &p : points)
    {
        while (s.size() >= 2)
        {
            auto second = s.top();
            s.pop();
            auto first = s.top();
            if (isCCW(first, second, p))
            {
                s.push(second);
                break;
            }
        }
        s.push(p);
    }
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());
}

double dist(Point &a, Point &b)
{
    ll dx = a.x - b.x, dy = a.y - b.y;
    if (dx == 0)
        return abs(dy);
    if (dy == 0)
        return abs(dx);
    return sqrt(dx * dx + dy * dy);
}
double getcos(Point &prev, Point &cur, Point &next)
{
    ll v1x = next.x - cur.x, v1y = next.y - cur.y, v2x = prev.x - cur.x, v2y = prev.y - cur.y;
    if (v1x * v2y == v1y * v2x)
        return 0;
    double cosvalue = (double)(v1x * v2x + v1y * v2y) / dist(next, cur) / dist(prev, cur);
    double theta = acos(cosvalue);
    return PI - theta;
}

bool linear()
{
    for (int i = 0; i < points.size() - 2; i++)
    {
        auto &prev = points[i], &cur = points[i + 1], &next = points[i + 2];
        ll dy1 = cur.y - prev.y, dx1 = cur.x - prev.x, dy2 = next.y - cur.y, dx2 = next.x - cur.x;
        if (dy1 * dx2 != dx1 * dy2)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(y, x));
    }

    if (linear()) // if all points are linear
    {
        sort(points.begin(), points.end());
        auto d = dist(points.front(), points.back());
        cout << (ll)((double)d * 2 + 2 * PI * l + 0.5) << '\n';
        return 0;
    }

    convexHull();
    double ans = 0;
    int siz = result.size();
    for (int i = 0; i < siz; i++)
    {
        auto &prev = result[(i - 1 + siz) % siz], &cur = result[i], &next = result[(i + 1) % siz];
        ans += dist(cur, next);
        ans += l * getcos(prev, cur, next);
    }
    cout << (ll)(ans + 0.5) << '\n';
}