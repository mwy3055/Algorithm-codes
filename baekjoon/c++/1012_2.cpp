#include <bits/stdc++.h>
using namespace std;
struct coord
{
    int y, x;
};
int n, m, k, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int board[50][50];
bool visit[50][50];

void init()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            board[i][j] = 0;
            visit[i][j] = false;
        }
    }
}
bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
void bfs(int y, int x)
{
    queue<coord> q;

    visit[y][x] = true;
    q.push({y, x});
    while (!q.empty())
    {
        auto top = q.front();
        auto &cy = top.y, &cx = top.x;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + src[i][0], nx = cx + src[i][1];
            if (isin(ny, nx) && board[ny][nx] == 1 && !visit[ny][nx])
            {
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}
int solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && !visit[i][j])
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int y, x;
            cin >> x >> y;
            board[y][x] = 1;
        }
        cout << solve() << '\n';
    }
}