#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
const int INF = 1e9;
int r, c, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char board[100][101];
bool visit[100][100];

bool yin(int y)
{
    return 0 <= y && y < r;
}
bool xin(int x)
{
    return 0 <= x && x < c;
}
bool isin(int y, int x)
{
    return yin(y) && xin(x);
}

void bfsinit()
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            visit[i][j] = false;
}
int maxdrop(int y, int x)
{
    int ans = 0;
    while (yin(y + 1) && (board[y + 1][x] == '.' || !visit[y + 1][x]))
        ans++, y++;
    return ans;
}
void bfs()
{
    bfsinit();
    queue<Coord> q;

    for (int j = 0; j < c; j++)
    {
        if (board[r - 1][j] == 'x')
        {
            q.push(Coord(r - 1, j));
            visit[r - 1][j] = true;
        }
    }
    while (!q.empty())
    {
        auto top = q.front();
        auto &y = top.first, &x = top.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && board[ny][nx] == 'x' && !visit[ny][nx])
            {
                q.push(Coord(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }
}
void stick(int &h, bool dir) // 0: left->right, 1: right->left
{
    int row = r - h, d = (dir ? -1 : 1), cur = (dir ? c - 1 : 0);
    while (xin(cur) && board[row][cur] != 'x')
        cur += d;

    if (!xin(cur))
        return;
    board[row][cur] = '.';
    bfs();

    vector<Coord> cluster;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] == 'x' && !visit[i][j])
                cluster.push_back(Coord(i, j));

    int drop = INF;
    for (auto &c : cluster)
        drop = min(drop, maxdrop(c.first, c.second));
    if (drop == 0 || drop == INF)
        return;
    for (auto &c : cluster)
        board[c.first][c.second] = '.';
    for (auto &c : cluster)
        board[c.first + drop][c.second] = 'x';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> board[i];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        stick(height, i % 2);
    }

    for (int i = 0; i < r; i++)
        cout << board[i] << '\n';
}