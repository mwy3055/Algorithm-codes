#include <bits/stdc++.h>

using ll = long long;
ll solve(int &n, std::vector<int> &prices)
{
    ll answer = 0;
    std::vector<int> after_max(n, 0);
    after_max.back() = prices.back();
    for (int i = n - 2; i >= 0; i--)
    {
        after_max[i] = std::max(after_max[i + 1], prices[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (prices[i] < after_max[i])
        {
            answer += after_max[i] - prices[i];
        }
    }

    return answer;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> prices;
        for (int i = 0; i < n; i++)
        {
            int p;
            std::cin >> p;
            prices.push_back(p);
        }
        std::cout << solve(n, prices) << '\n';
    }
}