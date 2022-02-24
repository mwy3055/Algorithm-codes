#include <bits/stdc++.h>
using namespace std;

int n, m, memory[101], cost[101], dp[101][10001]; // dp[i][j] : i번째 앱까지 j의 비용을 써서 얻을 수 있는 최대 메모리

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            if (j < cost[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
        }
    }

    for (int j = 0; j <= 10000; j++)
    {
        if (m <= dp[n][j])
        {
            cout << j;
            return 0;
        }
    }
}