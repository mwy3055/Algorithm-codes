#include <bits/stdc++.h>
using namespace std;

char board[5][6];
int dp[10][5][5]; //0: 탐색하지 않음, 1: 가능, 2: 불가능

void init()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 5; j++)
            memset(dp[i][j], 0, 5 * sizeof(int));
}

bool isin(int y, int x)
{
    return 0 <= y && y < 5 && 0 <= x && x < 5;
}
int dfs(int y, int x, string &s, int idx)
{
    if (s.length() - 1 == idx)
        return dp[idx][y][x] = (s[idx] == board[y][x] ? 1 : 2);
    if (dp[idx][y][x] != 0)
        return dp[idx][y][x];

    static int src[][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

    int &ret = dp[idx][y][x];
    ret = 2;
    for (int k = 0; k < 8; k++)
    {
        int sy = y + src[k][0], sx = x + src[k][1];
        if (isin(sy, sx) && board[sy][sx] == s[idx + 1])
            ret = min(ret, dfs(sy, sx, s, idx + 1));
        if (ret == 1)
            break;
    }

    return ret;
}
int solve(string &s)
{
    int ans = 2;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == s[0])
            {
                ans = min(ans, dfs(i, j, s, 0));
                if (ans == 1)
                    break;
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        for (int i = 0; i < 5; i++)
            cin >> board[i];

        int n;
        cin >> n;
        while (n--)
        {
            init();

            string s;
            cin >> s;
            int ans = solve(s);
            cout << s << ' ' << ((ans == 1) ? "YES" : "NO") << '\n';
        }
    }
}