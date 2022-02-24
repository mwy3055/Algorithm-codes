#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int y, x, key, cnt;
    Pair(int y, int x, int key, int cnt) : y(y), x(x), key(key), cnt(cnt) {}
};

int n, m;
char maze[50][51];
bool visit[50][50][1 << 6]; // bitmask bfs

bool haskey(int &key, int y, int x)
{
    return key & (1 << ('f' - maze[y][x]));
}
bool iskey(int y, int x)
{
    return 'a' <= maze[y][x] && maze[y][x] <= 'f';
}
bool isdoor(int y, int x)
{
    return 'A' <= maze[y][x] && maze[y][x] <= 'F';
}
bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
int bfs(int &sy, int &sx)
{
    static int d[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    queue<Pair> q;

    int cnt = 0;
    q.push(Pair(sy, sx, 0, 0));
    visit[sy][sx][0] = true;
    while (!q.empty())
    {
        auto top = q.front();
        int &cy = top.y, &cx = top.x, &key = top.key, &cnt = top.cnt;
        q.pop();
        if (maze[cy][cx] == '1')
            return cnt;
        else if (iskey(cy, cx))
            key |= (1 << ('f' - maze[cy][cx]));

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + d[i][0], nx = cx + d[i][1];
            if (!isin(ny, nx) || visit[ny][nx][key] || maze[ny][nx] == '#' || (isdoor(ny, nx) && !haskey(key, ny, nx)))
                continue;
            q.push(Pair(ny, nx, key, cnt + 1));
            visit[ny][nx][key] = true;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sy, sx;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '0')
                sy = i, sx = j;
        }
    }

    cout << bfs(sy, sx);
}