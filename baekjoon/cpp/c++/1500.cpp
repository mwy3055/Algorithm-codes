#include <bits/stdc++.h>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int s, k;
    std::cin >> s >> k;
    std::vector<ll> nums(k, s / k);
    for (int i = 0; i < s % k; i++)
    {
        nums[i]++;
    }

    ll ans = 1;
    for (auto &n : nums)
    {
        ans *= n;
    }
    std::cout << ans;
}