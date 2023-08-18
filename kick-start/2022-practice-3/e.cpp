#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9 + 7;

ll a, b, n, k;

void getinput()
{
    std::cin >> a >> b >> n >> k;
}

// x^p
ll pow(ll x, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x % k;
    auto half = pow(x, p / 2);
    ll result = (half % k) * (half % k);
    if (p % 2)
    {
        result = (result * x) % k;
    }
    return result;
}

ll solve()
{
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            auto watson = pow(i, a);
            auto sherlock = pow(j, b);
            auto remainder = ((watson % k) + (sherlock % k)) % k;
            if (remainder == 0)
                count = (count + 1) % MOD;
        }
    }
    return count;
}

// TLE for Test set 2
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        getinput();
        ll ans = solve();
        std::cout << "Case #" << i << ": " << ans << '\n';
    }
}