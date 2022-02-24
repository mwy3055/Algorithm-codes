#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1000000007;

int n;
std::vector<int> scobil;
std::vector<ll> front_sum; // 앞 i개의 합

ll back_sum(int i) // 뒤 i개의 합
{
    return (front_sum.back() - front_sum[n - i] + MOD) % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    scobil.resize(n);
    for (auto &s : scobil)
        std::cin >> s;

    // do what
    std::sort(scobil.begin(), scobil.end());
    front_sum.push_back(0);
    for (int i = 1; i <= n; i++)
        front_sum.push_back((front_sum.back() + scobil[i - 1]) % MOD);

    ll ans = 0, pow = 1;
    for (int i = 1; i <= n; i++)
    {
        // sum: 뒤 i개 - 앞 i개
        auto sum = (back_sum(i) - front_sum[i] + MOD) % MOD;
        ans = (ans + (sum * (pow % MOD))) % MOD;
        pow = (pow * 2) % MOD;
    }
    std::cout << ans << '\n';
}