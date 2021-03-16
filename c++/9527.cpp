#include <bits/stdc++.h>

using ll = long long;

// 2^i ~ 2^(i+1)-1
ll sq2(ll i)
{
    return (1 << (2 * i - 2)) + (1 << i);
}

ll log2(ll i)
{
    ll log = 0;
    while (i)
    {
        log++;
        i /= 2;
    }
    return log;
}

ll count(ll n)
{
    int ans = 0;
    while (n)
    {
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}

ll solve(ll a, ll b)
{
    ll ans = 0;
    // naive
    for (ll i = a; i <= b; i++)
        ans += count(i);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll a, b;
    std::cin >> a >> b;
    std::cout << solve(a, b);
}