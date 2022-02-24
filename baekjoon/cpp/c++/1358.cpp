#include <bits/stdc++.h>

int w, h, x, y, p, r;

int dist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

bool isin(int px, int py)
{
    // rectangle
    if ((x <= px && y <= py) && (px <= x + w && py <= y + h))
        return true;
    // left half circle
    if (dist(x, y + r, px, py) <= r * r)
        return true;
    // right half circle
    if (dist(x + w, y + r, px, py) <= r * r)
        return true;
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> w >> h >> x >> y >> p;
    r = h / 2;

    int ans = 0;
    for (int i = 0; i < p; i++)
    {
        int px, py;
        std::cin >> px >> py;
        if (isin(px, py))
            ans++;
    }
    std::cout << ans << '\n';
}