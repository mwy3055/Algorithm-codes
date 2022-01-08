#include <bits/stdc++.h>

double square(double d)
{
    return d * d;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, y, d, t;
    std::cin >> x >> y >> d >> t;

    double dist = std::sqrt(x * x + y * y);
    double ans = dist;

    int coef = 0;
    while (x * x + y * y > square(d * coef))
        coef++;
    double candidate;
    for (int i = 0; i <= coef; i++)
    {
        int r = d * i;
        candidate = t * i + std::abs(r - dist);
        ans = std::min(ans, candidate);
    }

    for (int i = 1; (i - 1) * d <= dist; i++)
    {
        if ((i - 1) * d < dist && dist <= (i + 1) * d)
        {
            candidate = (i + 1) * t;
            ans = std::min(ans, candidate);
        }
    }

    std::cout.precision(13);
    std::cout << std::fixed << ans << '\n';
}