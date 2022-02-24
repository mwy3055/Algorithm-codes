#include <bits/stdc++.h>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::vector<pll> segments;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        std::cin >> x >> y;
        segments.emplace_back(x, y);
    }
    std::sort(segments.begin(), segments.end());

    ll ans = 0;
    ll left = segments.front().first, right = segments.front().second;
    for (auto &seg : segments)
    {
        auto &seg_l = seg.first, &seg_r = seg.second;
        if (right < seg_l)
        {
            ans += right - left;
            left = seg_l;
            right = seg_r;
        }
        else
        {
            right = std::max(right, seg_r);
        }
    }
    ans += right - left;
    std::cout << ans;
}