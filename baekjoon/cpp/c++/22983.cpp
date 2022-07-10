#include <bits/stdc++.h>

using ll = long long;

int n, m;
bool b[3000][3000]; // B: true, W: false
ll dp[3000][3000];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++)
        {
            b[i][j] = (s[j] == 'B');
        }
    }
}

bool check(int r, int c)
{
    return b[r][c] != b[r - 1][c] &&
           b[r][c] != b[r][c - 1] &&
           b[r][c] == b[r - 1][c - 1];
}

ll solve()
{
    // 1915번과 동일한 점화식.
    // dp[i][j]: (i, j)가 마지막 점인 체스판의 수
    // 일단 자기 자신은 모두 올바른 체스판이다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // (i, j)를 끝점으로 길이 2 이상의 체스판을 만들 수 있는가?
            if (check(i, j))
            {
                // 이전 체스판 중 가장 큰 체스판의 한 변의 길이
                auto minv = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                dp[i][j] += minv;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += dp[i][j];
        }
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