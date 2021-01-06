#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<ll> m(n - 1), q(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> m[i];
    }

    q[n - 2] = m[n - 2];
    for (int i = n - 3; i >= 0; i--)
    {
        q[i] = (m[i] * (q[i + 1] + 1)) % MOD;
    }

    ll ans = 0;
    for (auto &qq : q)
        ans = (ans + qq) % MOD;
    std::cout << ans;
}