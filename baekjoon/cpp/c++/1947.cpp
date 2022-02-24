#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1000000000;
ll dp[1000001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    dp[0] = 1;
    // 계산
    for (int i = 2; i <= 1000000; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    int n;
    std::cin >> n;
    std::cout << dp[n];
}