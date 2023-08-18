#include <iostream>
#include <queue>
using namespace std;

int n, m, l, r;
char map[1000][1000];
bool visit[1000][1000];

class Coord
{
public:
    int y, x, l, r;
    Coord(int y = 0, int x = 0, int l = 0, int r = 0) : y(y), x(x), l(l), r(r) {}
    static bool isgo(int &y, int &x)
    {
        return 0 <= y && y < n && 0 <= x && x < m && map[y][x] == 0 && visit[y][x] == false;
    }
};

//»óÇÏ·Î´Â Âß ³Ö°í, ÁÂ¿ì·Î´Â ÇÑÄ­¾¿
int bfs(int &fy, int &fx)
{
    int cnt = 1;
    queue<Coord> q;

    q.push(Coord(fy, fx, l, r));
    visit[fy][fx] = true;

    while (!q.empty())
    {
        Coord top = q.front();
        q.pop();

        int sy = top.y - 1, sx = top.x;
        while (Coord::isgo(sy, sx))
        {
            visit[sy][sx] = true;
            q.push(Coord(sy, sx, top.l, top.r));
            cnt++;
            sy--;
        }

        sy = top.y + 1;
        while (Coord::isgo(sy, sx))
        {
            visit[sy][sx] = true;
            q.push(Coord(sy, sx, top.l, top.r));
            cnt++;
            sy++;
        }

        sy = top.y, sx = top.x - 1;
        if (0 < top.l && Coord::isgo(sy, sx))
        {
            visit[sy][sx] = true;
            q.push(Coord(sy, sx, top.l - 1, top.r));
            cnt++;
        }

        sx = top.x + 1;
        if (0 < top.r && Coord::isgo(sy, sx))
        {
            visit[sy][sx] = true;
            q.push(Coord(sy, sx, top.l, top.r - 1));
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> l >> r;
    int fy, fx;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            map[i][j] -= '0';
            if (map[i][j] == 2)
            {
                fy = i, fx = j;
            }
        }
    }

    cout << bfs(fy, fx);
}