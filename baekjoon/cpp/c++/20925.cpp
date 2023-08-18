#include <bits/stdc++.h>

struct field
{
    int min_exp, get_exp;
    field(int min_exp, int get_exp) : min_exp(min_exp), get_exp(get_exp) {}
};

int n, t;
int dist[200][200];
int dp[200][1050];
std::vector<field> fields;

void getinput()
{
    std::cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        int c, e;
        std::cin >> c >> e;
        fields.emplace_back(c, e);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> dist[i][j];
        }
    }
}

int solve()
{
    // dp[i][j]: 사냥터 i에 시간 j에 도착했을 때 얻을 수 있었던 경험치의 최댓값
    for (int j = 0; j < t; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // 사냥
            if (dp[i][j] >= fields[i].min_exp)
            {
                dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] + fields[i].get_exp);
            }
            // 이동
            for (int k = 0; k < n; k++)
            {
                if (j + dist[i][k] <= t && dp[i][j] >= fields[k].min_exp)
                {
                    dp[k][j + dist[i][k]] = std::max(dp[k][j + dist[i][k]], dp[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(ans, dp[i][t]);
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