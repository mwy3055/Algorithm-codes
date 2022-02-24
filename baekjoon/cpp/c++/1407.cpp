#include <bits/stdc++.h>

using ll = long long;
ll small[] = {0, 1, 3, 4};

ll solve(ll n) // f(1) + ... + f(n)
{
    if (n < 4)
        return small[n];
    ll k = (n >> 2) << 2;
    return k + solve(n % 4) + 4 * solve(k / 4);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll a, b;
    std::cin >> a >> b;
    std::cout << solve(b) - solve(a - 1);
}