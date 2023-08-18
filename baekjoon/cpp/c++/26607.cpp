#include <bits/stdc++.h>

int n, k, x;
std::vector<int> power;

// i번째 사람까지 볼 때, j명을 골라서 능력치 p를 만들 수 있는가?
bool dp[80][81][16001];

void getinput()
{
    std::cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        power.push_back(a);
    }
}

int solve()
{
    dp[0][1][power[0]] = true;
    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = true;
        dp[i][1][power[i]] = true;
        for (int j = 1; j <= i + 1; j++)
        {
            for (int p = 0; p <= x * k; p++)
            {
                // i번째 사람을 고르는 경우
                if (p - power[i] >= 0 && j > 0)
                    dp[i][j][p] |= dp[i - 1][j - 1][p - power[i]];
                // i번째 사람을 안 고르는 경우
                dp[i][j][p] |= dp[i - 1][j][p];
            }
        }
    }

    int ans = 0;
    for (int p = 0; p <= x * k; p++)
    {
        if (dp[n - 1][k][p])
            ans = std::max(ans, p * (k * x - p));
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}