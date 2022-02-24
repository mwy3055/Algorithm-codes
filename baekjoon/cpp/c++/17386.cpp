#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;

int ccw(pair<int, int> x, pair<int, int> y, pair<int, int> z) // (x, y)
{
    ll v1x = y.first - x.first, v1y = y.second - x.second;
    ll v2x = z.first - y.first, v2y = z.second - y.second;
    ll cross = v1x * v2y - v1y * v2x;
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}
bool meet_segment(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) // (x1, y1) ~ (x2, y2), (x3, y3) ~ (x4, y4)
{
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pii a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    cout << meet_segment(a, b, c, d);
}