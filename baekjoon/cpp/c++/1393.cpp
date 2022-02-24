#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    //constraint: a <= b
    if (a > b)
    {
        swap(a, b);
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

int sq(int s)
{
    return s * s;
}

int main()
{
    int x, y, X, Y, dx, dy;
    cin >> x >> y >> X >> Y >> dx >> dy;
    if (dx != 0 && dy != 0)
    {
        int gcd = GCD(abs(dx), abs(dy));
        dx /= gcd, dy /= gcd;
    }
    else if (dx == 0 && dy == 0)
    {
        cout << X << ' ' << Y;
        return 0;
    }
    else if (dx == 0)
    {
        dy /= abs(dy);
    }
    else if (dy == 0)
    {
        dx /= abs(dx);
    }

    int mx = X, my = Y, mdist = sq(x - X) + sq(y - Y);
    while (abs(X) < 200 && abs(Y) < 200)
    {
        X += dx, Y += dy;
        int curDist = sq(x - X) + sq(y - Y);
        if (curDist < mdist)
        {
            mx = X, my = Y;
            mdist = curDist;
        }
    }

    cout << mx << ' ' << my;
}