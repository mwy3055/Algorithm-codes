#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> coord;
struct node
{
    int cnt, dir;
    coord c;
    node(int cnt, int dir, coord c) : cnt(cnt), dir(dir), c(c) {}
    bool operator>(node n) const
    {
        return this->cnt > n.cnt;
    }
};

int n, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0}, rot[][4] = {3, 2, 1, 0, 1, 0, 3, 2};
char board[50][51];
vector<coord> doors;

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool cango(int ny, int nx, int dir)
{
    return isin(ny, nx) && board[ny][nx] != '*';
}
int solve()
{
    priority_queue<node, vector<node>, greater<node>> pq;

    auto &d = doors[0];
    for (int i = 0; i < 4; i++)
        pq.push(node(0, i, d));
    while (!pq.empty())
    {
        auto top = pq.top();
        auto &cnt = top.cnt, &dir = top.dir;
        auto &c = top.c;
        pq.pop();

        if (c == doors[1])
            return cnt;
        if (board[c.first][c.second] == '!')
        {
            for (int i = 0; i < 2; i++)
            {
                int ndir = rot[i][dir], ncnt = cnt + 1;
                int ny = c.first + src[ndir][0], nx = c.second + src[ndir][1];
                if (cango(ny, nx, ndir))
                {
                    pq.push(node(ncnt, ndir, coord(ny, nx)));
                }
            }
        }
        int ny = c.first + src[dir][0], nx = c.second + src[dir][1];
        if (cango(ny, nx, dir))
        {
            pq.push(node(cnt, dir, coord(ny, nx)));
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '#')
                doors.push_back(coord(i, j));
        }
    }

    cout << solve();
}