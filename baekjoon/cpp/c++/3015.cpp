#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> heights;
    for (int i = 0; i < n; i++)
    {
        int h;
        std::cin >> h;
        heights.push_back(h);
    }

    std::stack<pii> s;
    ll ans = 0;
    for (auto &h : heights)
    {
        auto p = pii(h, 1);
        while (!s.empty() && s.top().first <= h)
        {
            ans += s.top().second;
            if (s.top().first == h)
            {
                p.second += s.top().second;
            }
            s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(p);
    }
    std::cout << ans;
}