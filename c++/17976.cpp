#include <bits/stdc++.h>

using thread = std::pair<int, int>; // start, length
using ll = long long;

int n;
std::vector<thread> threads;

bool check(ll dist)
{
    ll x = threads.front().first;
    for (int i = 1; i < n; i++)
    {
        auto &t = threads[i];
        if (t.first - x >= dist)
            x = t.first;
        else if (t.first + t.second - x >= dist)
            x += dist;
        else
            return false;
    }
    return true;
}

ll solve()
{
    ll l = 1, r = threads.back().first + threads.back().second + 1;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, l;
        std::cin >> x >> l;
        threads.emplace_back(x, l);
    }

    std::sort(threads.begin(), threads.end());
    std::cout << solve() << '\n';
}