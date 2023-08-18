#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : y(y), x(x) {}
    bool operator<(const point &p) const
    {
        if (this->y == p.y)
            return this->x < p.x;
        return this->y < p.y;
    }
};
bool sortcmp(const point &a, const point &b)
{
    return a.x < b.x;
}
int dist(point a, point b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    point p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    sort(p, p + n, sortcmp);

    set<point> candidate = {p[0], p[1]};
    int ans = dist(p[0], p[1]), start = 0;
    for (int i = 2; i < n; i++)
    {
        point now = p[i];
        while (start < i)
        {

            int dx = now.x - p[start].x;
            if (ans < dx * dx)
            {
                candidate.erase(p[start]);
                start++;
            }
            else
                break;
        }

        int d = (int)sqrt(ans) + 1;
        auto lp = candidate.lower_bound(point(-20000, now.y - d));
        auto up = candidate.upper_bound(point(20000, now.y + d));
        for (auto it = lp; it != up; it++)
        {
            ans = min(ans, dist(now, *it));
        }
        candidate.insert(now);
    }
    cout << ans;
}