#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
ll xcount[100001], ycount[100001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::vector<pii> points;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x, y);
        xcount[x]++;
        ycount[y]++;
    }

    ll ans = 0;
    for (auto &point : points)
    {
        auto &x = point.first, &y = point.second;
        if (xcount[x] > 1 && ycount[y] > 1)
            ans += (xcount[x] - 1) * (ycount[y] - 1);
    }
    std::cout << ans;
}