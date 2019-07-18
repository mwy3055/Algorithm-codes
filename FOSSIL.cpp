#include <bits/stdc++.h>
using namespace std;

struct point
{
    double y, x;
};

vector<point> hull1, hull2;
vector<pair<point, point>> upper, lower;

double minX(const vector<point> &hull)
{
    double rtn = 1e20;
    for (auto &point : hull)
        rtn = min(rtn, point.x);
    return rtn;
}
double maxX(const vector<point> &hull)
{
    double rtn = -1e20;
    for (auto &point : hull)
        rtn = max(rtn, point.x);
    return rtn;
}
void decompose(const vector<point> &hull)
{
    int siz = hull.size();
    for (int i = 0; i < siz; i++)
    {
        if (hull[i].x < hull[(i + 1) % siz].x)
            lower.push_back(make_pair(hull[i], hull[(i + 1) % siz]));
        else if (hull[i].x > hull[(i + 1) % siz].x)
            upper.push_back(make_pair(hull[i], hull[(i + 1) % siz]));
    }
}

bool between(const point &a, const point &b, double x)
{
    return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double meet_y(const point &a, const point &b, double x)
{
    double dx = b.x - a.x, dy = b.y - a.y;
    return a.y + dy / dx * (x - a.x);
}

double meetWidth(double x)
{
    double minUp = 1e10, maxLow = -(1e10);

    for (const auto &segment : upper)
    {
        if (between(segment.first, segment.second, x))
            minUp = min(minUp, meet_y(segment.first, segment.second, x));
    }
    for (const auto &segment : lower)
    {
        if (between(segment.first, segment.second, x))
            maxLow = max(maxLow, meet_y(segment.first, segment.second, x));
    }

    return minUp - maxLow;
}
double solve()
{
    double l = max(minX(hull1), minX(hull2));
    double r = min(maxX(hull1), maxX(hull2));
    if (l > r)
        return 0;

    for (int i = 0; i < 100; i++)
    {
        double first = (l * 2 + r) / 3, second = (l + r * 2) / 3;
        if (meetWidth(first) < meetWidth(second))
            l = first;
        else
            r = second;
    }
    return max(0.0, meetWidth(r));
}

void clearData()
{
    hull1.clear();
    hull2.clear();
    upper.clear();
    lower.clear();
}
void getData()
{
    int n, m;
    cin >> n >> m;
    hull1.resize(n);
    hull2.resize(m);
    for (int i = 0; i < n; i++)
        cin >> hull1[i].x >> hull1[i].y;
    for (int i = 0; i < m; i++)
        cin >> hull2[i].x >> hull2[i].y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(8);

    int t;
    cin >> t;
    while (t--)
    {
        clearData();
        getData();

        decompose(hull1);
        decompose(hull2);
        cout << solve() << '\n';
    }
}