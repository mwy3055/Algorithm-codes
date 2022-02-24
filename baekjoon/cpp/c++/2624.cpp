#include <bits/stdc++.h>

using pii = std::pair<int, int>; // price, count

// dp[i][j]: i번까지의 동전을 사용해서 j원을 만드는 경우의 수
// 동전 번호는 0번부터 시작
int dp[101][10001];

int solve(int t, int k, std::vector<pii> &coins)
{
    // 기저
    for (int j = 0; j <= coins[0].second; j++)
        dp[0][j * coins[0].first] = 1;
    // 계산
    for (int i = 1; i < k; i++)
    {
        auto &[price, count] = coins[i];
        dp[i][0] = 1;
        for (int j = 1; j <= t; j++)
        {
            if (j < price)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                for (int c = 0; c <= count; c++)
                {
                    if (j - c * price >= 0)
                        dp[i][j] += dp[i - 1][j - c * price];
                }
            }
        }
    }
    return dp[k - 1][t];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t, k;
    std::cin >> t >> k;
    std::vector<pii> coins;
    for (int i = 0; i < k; i++)
    {
        int p, n;
        std::cin >> p >> n;
        coins.emplace_back(p, n);
    }
    std::sort(coins.begin(), coins.end());
    std::cout << solve(t, k, coins);
}