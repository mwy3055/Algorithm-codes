#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point; // y, x

vector<Point> points;
bool comp(Point &a, Point &b) // sort points by CCW orientation
{
    ll aq = (a.first - points[0].first), ap = (a.second - points[0].second);
    ll bq = (b.first - points[0].first), bp = (b.second - points[0].second);
    if (aq * bp != ap * bq)
        return aq * bp < ap * bq;
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
bool isCCW(Point &a, Point &b, Point &c)
{
    return (b.second - a.second) * (c.first - a.first) > (b.first - a.first) * (c.second - a.second);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    points.resize(n);
    for (auto &p : points)
        cin >> p.second >> p.first;

    // sort(points.begin(), points.end());
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), comp);

    stack<Point> s;
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
    cout << s.size() << '\n';
}