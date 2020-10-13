#include <bits/stdc++.h>

const int MOD = 1000000000;
int n, dp[101][10][1 << 10]; // 길이, 끝자리 수, 비트마스크

// bitmask operations
bool contains(int bit, int i)
{
    return bit & (1 << i);
}
int remove(int bit, int i)
{
    return bit ^ (1 << i);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    // calculate
    for (int i = 1; i < 10; i++)
        dp[1][i][1 << i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int bit = 1; bit < 1024; bit++)
            {
                if (!contains(bit, j))
                    continue;
                auto &d = dp[i][j][bit];
                if (j + 1 < 10)
                {
                    d = (d + dp[i - 1][j + 1][bit]) % MOD;
                    d = (d + dp[i - 1][j + 1][remove(bit, j)]) % MOD;
                }
                if (j - 1 >= 0)
                {
                    d = (d + dp[i - 1][j - 1][bit]) % MOD;
                    d = (d + dp[i - 1][j - 1][remove(bit, j)]) % MOD;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + dp[n][i][1023]) % MOD;
    std::cout << sum;
}