#include <bits/stdc++.h>

using ll = long long;

ll solve(std::vector<int> &woods, int c, int w, int len)
{
    ll ans = 0;
    for (auto &wood : woods)
    {
        int pieces = wood / len;
        int cutcount;
        if (wood % len == 0)
            cutcount = pieces - 1;
        else
            cutcount = pieces;
        ll profit = pieces * w * len - c * cutcount;
        if (profit > 0)
            ans += profit;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, c, w;
    std::cin >> n >> c >> w;
    std::vector<int> woods;
    for (int i = 0; i < n; i++)
    {
        int l;
        std::cin >> l;
        woods.push_back(l);
    }

    std::sort(woods.begin(), woods.end());
    ll maxlen = woods.back(), ans = 0;
    for (int len = 1; len <= maxlen; len++)
    {
        ans = std::max(ans, solve(woods, c, w, len));
    }
    std::cout << ans;
}