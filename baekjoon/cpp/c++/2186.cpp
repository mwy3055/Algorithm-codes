#include <bits/stdc++.h>
using namespace std;

char board[100][101];
int dp[80][100][100]; //[dep][y][x], 0: 탐색 안됨, -1: 불가능, else: 여기서부터 가능한 경로 수
int n, m, k, dans;
string target;

struct coord
{
    int y, x;
    coord(int y, int x) : y(y), x(x) {}
};

void getinput()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    cin >> target;
}
void init()
{
    int len = target.length();
    for (int l = 0; l < len; l++)
    {
        for (int y = 0; y < n; y++)
            memset(*(dp + l) + y, -1, sizeof(int) * m);
    }
}
bool isin(const int &y, const int &x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
int dfs(int y, int x, int dep) //(y, x)에 dep번째 문자가 있음
{
    static int len = target.length();
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

    if (dp[dep][y][x] >= 0)
        return dp[dep][y][x];
    if (dep + 1 == len)
        return dp[dep][y][x] = 1;

    int tans = 0;
    for (int d = 1; d <= k; d++)
    {
        for (int i = 0; i < 4; i++)
        {
            int sy = y + src[i][0] * d, sx = x + src[i][1] * d;
            if (isin(sy, sx) && board[sy][sx] == target[dep + 1])
            {
                tans += dfs(sy, sx, dep + 1);
            }
        }
    }

    return dp[dep][y][x] = tans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();
    init();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == target[0])
            {
                dans += dfs(i, j, 0);
            }
        }
    }

    cout << dans;
}