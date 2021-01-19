#include <bits/stdc++.h>

using vi = std::vector<int>;
int solve(int &n, int &m, vi &prices, vi &prefs)
{
    int count = 201, dp[201] = {0}, max = 0;
    for (int i = 1; i <= m; i++)
    {
        int cidx = i % count, tmax = 0;
        for (int j = 0; j < n; j++)
        {
            if (i >= prices[j])
            {
                tmax = std::max(tmax, dp[(i - prices[j]) % count] + prefs[j]);
            }
        }
        dp[cidx] = tmax;
        max = std::max(max, tmax);
    }
    return max;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        int n, m;
        std::cin >> n >> m;
        m /= 100;
        vi prices, prefs;
        for (int i = 0; i < n; i++)
        {
            int price, pref;
            std::cin >> price >> pref;
            price /= 100;
            prices.push_back(price);
            prefs.push_back(pref);
        }
        std::cout << solve(n, m, prices, prefs) << '\n';
    }
}