#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
const int INF = 10000;
int n, m, dp[50][50];
char board[50][51];
bool visit[50][50];

void init()
{
    for (int i = 0; i < 50; i++)
        memset(dp + i, -1, sizeof(int) * 50);
}

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
int solve(int y, int x)
{
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

    int &ret = dp[y][x];
    if (visit[y][x])
        return ret = INF;
    if (ret != -1)
        return ret;
    if (board[y][x] == 'H')
        return ret = 0;

    ret = 1;
    visit[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + src[i][0] * (board[y][x] - '0'), nx = x + src[i][1] * (board[y][x] - '0');
        if (isin(ny, nx))
        {
            ret = max(ret, solve(ny, nx) + 1);
        }
    }
    visit[y][x] = false;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int ans = solve(0, 0);
    cout << (ans >= INF ? -1 : ans);
}