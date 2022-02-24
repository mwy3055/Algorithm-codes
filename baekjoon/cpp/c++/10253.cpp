#include <bits/stdc++.h>

using ll = long long;

ll GCD(ll a, ll b)
{
    //constraint: a <= b
    if (a > b)
        std::swap(a, b);
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

// find largest x such that 1/x <= a/b
ll psearch(ll a, ll b)
{
    int l = 1, r = b + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (b <= a * mid)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l + 1;
}

ll solve(ll a, ll b)
{
    ll ans;
    while (a > 0)
    {
        auto gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        if (b % a == 0)
        {
            ans = b / a;
            break;
        }
        ans = psearch(a, b);
        a = a * ans - b;
        b *= ans;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << solve(a, b) << '\n';
    }
}