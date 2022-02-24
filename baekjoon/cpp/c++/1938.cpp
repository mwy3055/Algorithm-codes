#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
struct state
{
    Coord c;
    int rotate; // 0: horizontal, 1: vertical
    state(int y = 0, int x = 0, int rotate = 0) : c(Coord(y, x)), rotate(rotate) {}
    bool operator==(const state &s)
    {
        return (this->c == s.c) && (this->rotate == s.rotate);
    }
};
int n;
char board[50][51];
bool visit[50][50][2];

bool isin(int y, int x, int r)
{
    if (r) // vertical
        return (0 <= y - 1 && y + 1 < n) && (0 <= x && x < n);
    else
        return (0 <= y && y < n) && (0 <= x - 1 && x + 1 < n);
}
bool cango(int y, int x, int r)
{
    if (r)
    {
        for (int sy = y - 1; sy <= y + 1; sy++)
            if (board[sy][x] == '1')
                return false;
        return true;
    }
    else
    {
        for (int sx = x - 1; sx <= x + 1; sx++)
            if (board[y][sx] == '1')
                return false;
        return true;
    }
}
bool canrotate(int y, int x, int r)
{
    if (!(0 <= y - 1 && y - 1 < n && 0 <= x - 1 && x - 1 < n) || !(0 <= y + 1 && y + 1 < n && 0 <= x + 1 && x + 1 < n))
        return false;
    for (int sy = y - 1; sy <= y + 1; sy++)
    {
        for (int sx = x - 1; sx <= x + 1; sx++)
        {
            if (board[sy][sx] == '1')
                return false;
        }
    }
    return true;
}
int bfs(state &s, state &e)
{
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    queue<state> q;

    visit[s.c.first][s.c.second][s.rotate] = true;
    q.push(s);

    int cnt = 0;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto y = top.c.first, x = top.c.second, r = top.rotate;
            q.pop();
            if (top == e)
                return cnt;

            for (int i = 0; i < 4; i++)
            {
                int sy = y + src[i][0], sx = x + src[i][1];
                if (isin(sy, sx, r) && cango(sy, sx, r) && !visit[sy][sx][r])
                {
                    visit[sy][sx][r] = true;
                    q.push(state(sy, sx, r));
                }
            }
            if (canrotate(y, x, r) && !visit[y][x][1 - r])
            {
                visit[y][x][1 - r] = true;
                q.push(state(y, x, 1 - r));
            }
        }
        cnt++;
    }
    return 0;
}

void getpoint(state &s, vector<Coord> &v)
{
    s.c = v[1];
    if (v[0].first == v[1].first)
        s.rotate = 0;
    else
        s.rotate = 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<Coord> begin, end;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'B')
                begin.push_back(Coord(i, j));
            if (board[i][j] == 'E')
                end.push_back(Coord(i, j));
        }
    }

    state start, finish;
    getpoint(start, begin);
    getpoint(finish, end);

    cout << bfs(start, finish);
}