#include <bits/stdc++.h>

using ll = long long;

int n;
ll dp[31], mirror[31];

void getinput()
{
    std::cin >> n;
}

ll solve()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    if (n < 3)
        return dp[n];

    // 일단 중복 고려하지 않고
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    // 중복되어 세지지 않는 것들을 더한 후 (좌우대칭)
    for (int i = 3; i <= n; i++)
    {
        if (i % 2)
        {
            // 홀수: 가운데 하나 놓고 좌우대칭
            mirror[i] = dp[(i - 1) / 2];
        }
        else
        {
            // 짝수
            // mirror[i] = dp[i / 2] + 2 * dp[i / 2 - 1];
            mirror[i] = dp[i / 2 + 1];
        }
    }

    // 2로 나누자.
    return (dp[n] + mirror[n]) / 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}