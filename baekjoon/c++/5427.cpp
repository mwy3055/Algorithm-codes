#include <bits/stdc++.h>
using namespace std;

class Coord
{
public:
    int y, x;
    Coord(int y = 0, int x = 0) : y(y), x(x) {}
    static bool isin(int &h, int &w, Coord &c)
    {
        return 0 <= c.y && c.y < h && 0 <= c.x && c.x < w;
    }
    static bool isin(int &h, int &w, int y, int x)
    {
        return 0 <= y && y < h && 0 <= x && x < w;
    }
};

int h, w;
vector<vector<bool>> isfire, isvisit;
vector<string> Map;
queue<Coord> fire, q;
int src[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

void bfs_fire()
{
    int siz = fire.size();
    while (siz--)
    {
        Coord top = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++)
        {
            int sy = top.y + src[i][0], sx = top.x + src[i][1];
            if (Coord::isin(h, w, sy, sx) && Map[sy][sx] == '.' && isfire[sy][sx] == false)
            {
                isfire[sy][sx] = true;
                fire.push(Coord(sy, sx));
            }
        }
    }
}

bool cannot_go(int &y, int &x)
{
    return isfire[y][x] || isvisit[y][x] || Map[y][x] != '.';
}
bool bfs_sk()
{
    int siz = q.size();
    while (siz--)
    {
        Coord top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int sy = top.y + src[i][0], sx = top.x + src[i][1];
            if (Coord::isin(h, w, sy, sx) == false)
                return true;
            if (cannot_go(sy, sx))
                continue;

            isvisit[sy][sx] = true;
            q.push(Coord(sy, sx));
        }
    }
    return false;
}

void bfs_init(Coord &start)
{
    isfire = vector<vector<bool>>(h, vector<bool>(w, false));
    isvisit = vector<vector<bool>>(h, vector<bool>(w, false));
    while (!fire.empty())
        fire.pop();
    while (!q.empty())
        q.pop();

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (Map[y][x] == '*')
            {
                isfire[y][x] = true;
                fire.push(Coord(y, x));
            }
            else if (Map[y][x] == '@')
                start = Coord(y, x);
        }
    }
}
int bfs()
{
    Coord start;
    bfs_init(start);

    q.push(start);
    isvisit[start.y][start.x] = true;

    int time = 0;
    while (!q.empty())
    {
        bfs_fire();
        if (bfs_sk())
            return time + 1;

        time++;
    }
    return -1;
}

int solve()
{
    cin >> w >> h;
    Map = vector<string>(h);
    for (int i = 0; i < h; i++)
        cin >> Map[i];

    return bfs();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int rtn = solve();
        if (rtn == -1)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << rtn << '\n';
    }
}
