#include <bits/stdc++.h>

std::vector<int> primes;
int dp[1121][15][188]; // [1, 1120] 구간의 소수는 187개

void preprocess()
{
    primes.push_back(2);
    for (int i = 3; i <= 1120; i++)
    {
        bool isprime = true;
        auto limit = std::sqrt(i);
        for (int j = 2; j <= limit + 1; j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
            primes.push_back(i);
    }
}

// n을 k개의 서로 다른 소수의 합으로 나타낼 수 있는 경우의 수
// 이때 s번 소수부터 사용한다.
int solve(int n, int k, int s)
{
    auto &ret = dp[n][k][s];
    if (ret != -1)
        return ret;
    if (n == 0)
        return ret = (k == 0);
    if (k == 0)
        return ret = (n == 0);
    ret = 0;
    for (int i = s; i < primes.size() && primes[i] <= n; i++)
    {
        auto part = solve(n - primes[i], k - 1, i + 1);
        ret += part;
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // 소수 구하기
    preprocess();
    std::memset(dp, -1, sizeof(dp));

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << solve(n, k, 0) << '\n';
    }
}