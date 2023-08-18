#include <bits/stdc++.h>

using vi = std::vector<int>;
using pii = std::pair<int, int>;
// INF: 불가능한 방법
const int INF = 0x3f3f3f3f;
int n, w, enemy[2][10001], dp[3][10001];

void solve()
{
    // 원형이 아니라 직사각형 건물을 생각해 보자.
    // dp[0][i]: 1행은 i열, 2행은 (i-1)열까지 특수소대로 채울 때
    // dp[1][i]: 1행은 (i-1)열, 2행은 i열까지 특수소대로 채울 때
    // dp[2][i]: 1행과 2행 모두 (i-1)열까지 특수소대로 채울 때
    for (int i = 2; i <= n; i++)
    {
        // 0행의 (i-1)열, i열에 투입해야 하는 소대의 수
        // 1행의 (이하동문)
        // i열에 투입해야 하는 소대의 수
        int upline = 2 - (enemy[0][i] + enemy[0][i - 1] <= w);
        int downline = 2 - (enemy[1][i] + enemy[1][i - 1] <= w);
        int updown = 2 - (enemy[0][i] + enemy[1][i] <= w);
        dp[0][i] = std::min(dp[1][i - 1] + upline, dp[2][i - 1] + 1);
        dp[1][i] = std::min(dp[0][i - 1] + downline, dp[2][i - 1] + 1);
        dp[2][i] = std::min(std::min(dp[0][i] + 1, dp[1][i] + 1),
                            std::min(dp[2][i - 1] + updown, dp[2][i - 2] + upline + downline));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));

        std::cin >> n >> w;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cin >> enemy[i][j];
            }
        }
        if (n == 1)
        {
            std::cout << 2 - (enemy[0][1] + enemy[1][1] <= w) << '\n';
            continue;
        }

        int ans;
        // solve()는 직사각형 건물에 대한 문제를 푼다.
        // 이 문제의 건물은 원형이므로 1열과 n열을 하나의 소대가 담당할 수 있는 경우를 따져봐야 한다.
        // 동시에 담당 불가능
        dp[0][1] = dp[1][1] = 1;
        dp[2][1] = 2 - (enemy[0][1] + enemy[1][1] <= w);
        solve();
        ans = dp[2][n];
        // 0행 1열과 n열을 동시에
        if (enemy[0][1] + enemy[0][n] <= w)
        {
            dp[2][0] = INF;
            dp[0][1] = 1;
            dp[1][1] = INF;
            dp[2][1] = 2;
            solve();
            ans = std::min(ans, dp[1][n]);
        }
        // 1행 1열과 n열을 동시에
        if (enemy[1][1] + enemy[1][n] <= w)
        {
            dp[2][0] = INF;
            dp[0][1] = INF;
            dp[1][1] = 1;
            dp[2][1] = 2;
            solve();
            ans = std::min(ans, dp[0][n]);
        }
        // 0행 1열과 n열을, 1행 1열과 n열을 모두 동시에
        if (enemy[0][1] + enemy[0][n] <= w && enemy[1][1] + enemy[1][n] <= w)
        {
            dp[2][0] = INF;
            dp[0][1] = INF;
            dp[1][1] = INF;
            dp[2][1] = 2;
            solve();
            ans = std::min(ans, dp[2][n - 1]);
        }
        std::cout << ans << '\n';
    }
}