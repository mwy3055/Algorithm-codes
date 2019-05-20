#include <bits/stdc++.h>
using namespace std;

class circle
{
public:
    int y, x, r;
    circle(int y = 0, int x = 0, int r = 0) : y(y), x(x), r(r) {}
    bool isin(double y, double x)
    {
        double dy = this->y - y, dx = this->x - x;
        return dy * dy + dx * dx <= r * r;
    }
};

istream &operator>>(istream &in, circle &c)
{
    in >> c.x >> c.y >> c.r;
    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    circle c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    double ans = 0;
    for (double i = 0; i <= 100; i += 0.5)
    {
        for (double j = 0; j <= 100; j += 0.5)
        {
            if (c1.isin(i, j) || c2.isin(i, j) || c3.isin(i, j))
                ans += 0.25;
        }
    }
    cout << ans;
}