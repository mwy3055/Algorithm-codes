#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9 + 7;

ll fac[400001];

// x^n
ll pow(ll x, ll n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    auto result = pow(x, n / 2) % MOD;
    result = (result * result) % MOD;
    if (n % 2)
        result = (result * x) % MOD;
    return result;
}

void preprocess()
{
    fac[1] = 1;
    for (int i = 2; i <= 400000; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

// 페르마의 소정리
ll comb(ll n, ll k)
{
    ll a = fac[n], b = fac[k], c = fac[n - k];
    ll power = pow((b * c) % MOD, MOD - 2);
    return (a * power) % MOD;
}

ll solve(int m)
{
    preprocess();
    ll ans = 0;
    for (int i = 3; i <= m; i++)
    {
        ans = (ans + comb(2 * i, i)) % MOD;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int m;
    std::cin >> m;
    std::cout << solve(m) << '\n';
}