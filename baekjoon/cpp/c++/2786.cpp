#include <bits/stdc++.h>

using ll = long long;
using pll = std::pair<ll, ll>;
bool used[500000];

void solve(int &n, std::vector<pll> &prices)
{
    std::vector<pll> first, other, diff;
    for (int i = 0; i < n; i++)
    {
        first.emplace_back(prices[i].first, i);
        other.emplace_back(prices[i].second, i);
        diff.emplace_back(prices[i].first - prices[i].second, i);
    }
    std::sort(first.begin(), first.end());
    std::sort(other.begin(), other.end());

    // other[0] ~ other[i]의 합
    std::vector<ll> other_sum;
    other_sum.push_back(other[0].first);
    for (int i = 1; i < n; i++)
    {
        other_sum.push_back(other[i].first + other_sum.back());
    }

    std::cout << first[0].first << '\n';
    // 1) 가장 저렴한 (i-1)개의 other와, 안 시킨 음식 중 가장 저렴한 first (f1)
    int f1 = 0;
    // 2) 가장 저렴한 i개의 other 중 (first-other)가 가장 작은 음식(f2)을 맨 처음 주문
    int f2 = other[0].second;
    for (int i = 2; i <= n; i++)
    {
        ll min1, min2;
        // 1)
        used[other[i - 2].second] = true;
        if (other[i - 2].second == first[f1].second)
        {
            while (used[first[f1].second])
            {
                f1++;
            }
        }
        min1 = other_sum[i - 2] + first[f1].first;
        // 2)
        ll new_idx = other[i - 1].second;
        if (diff[new_idx].first < diff[f2].first)
        {
            f2 = new_idx;
        }
        min2 = other_sum[i - 1] + diff[f2].first;
        std::cout << std::min(min1, min2) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<pll> prices(n);
    for (auto &p : prices)
        std::cin >> p.first >> p.second;
    solve(n, prices);
}