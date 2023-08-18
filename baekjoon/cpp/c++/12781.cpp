#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int ccw(pii x, pii y, pii z) // (x, y)
{
    int v1x = y.first - x.first, v1y = y.second - x.second;
    int v2x = z.first - y.first, v2y = z.second - y.second;
    int cross = v1x * v2y - v1y * v2x;
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pii a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    cout << (ccw(a, b, c) * ccw(a, b, d) < 0);
}