#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
char board[8][9];
bool visit[100][8][8]; // max move: 8*8 + 8 + 8
int src[][2] = {1, 0, 1, 1, 1, -1, 0, 1, 0, -1, -1, -1, -1, 0, -1, 1};

void walldrop()
{
    for (int i = 6; i >= 0; i--)
    {
        memcpy(board + i + 1, board + i, sizeof(char) * 8);
    }
    memset(board, '.', sizeof(char) * 8);
}
bool isin(int y, int x)
{
    return 0 <= y && y < 8 && 0 <= x && x < 8;
}
int solve()
{
    Coord finish(0, 7);
    queue<Coord> q;

    int cnt = 0;
    visit[0][7][0] = true;
    q.push(Coord(7, 0));
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto &y = top.first, &x = top.second;
            q.pop();

            if (top == finish)
                return 1;
            if (board[y][x] == '#')
                continue;
            for (int i = 0; i < 8; i++)
            {
                int ny = y + src[i][0], nx = x + src[i][1];
                if (isin(ny, nx) && !visit[cnt][ny][nx] && board[ny][nx] != '#')
                {
                    visit[cnt][ny][nx] = true;
                    q.push(Coord(ny, nx));
                }
            }
            q.push(top);
        }
        walldrop();
        cnt++;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 8; i++)
        cin >> board[i];
    cout << solve();
}