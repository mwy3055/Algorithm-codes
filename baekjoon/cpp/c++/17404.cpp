#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, val[1000][3], dp[1000][3]; // 0이면 탐색 안 된 것, R G B - 0 1 2, dp[i][j]는 i번째 집까지 j색으로 칠했을 때의 최솟값
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> val[i][j];
        }
    }
    memcpy(dp, val, sizeof(int) * 3);

    int ans = INF;
    for (int c = 0; c < 3; c++) // 첫 번째 집의 색깔
    {
        int &k1 = dp[0][(c + 1) % 3], &k2 = dp[0][(c + 2) % 3];
        int bk1 = k1, bk2 = k2;
        k1 = k2 = INF;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = val[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }
        ans = min({ans, dp[n - 1][(c + 1) % 3], dp[n - 1][(c + 2) % 3]});
        k1 = bk1, k2 = bk2;
    }

    cout << ans;
}