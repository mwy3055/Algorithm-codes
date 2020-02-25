#include <bits/stdc++.h>
using namespace std;

class Coord
{
public:
    int y, x;
    Coord(int y = 0, int x = 0) : y(y), x(x) {}
};

int r, c;
bool isfire[1000][1000], isvisit[1000][1000];
char Map[1000][1001];
queue<Coord> fire, q;
int src[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

bool isin(Coord &C)
{
    return 0 <= C.y && C.y < r && 0 <= C.x && C.x < c;
}
bool isin(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

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
            if (isin(sy, sx) && Map[sy][sx] == '.' && isfire[sy][sx] == false)
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
            if (isin(sy, sx) == false)
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
    while (!fire.empty())
        fire.pop();
    while (!q.empty())
        q.pop();

    for (int y = 0; y < c; y++)
    {
        for (int x = 0; x < r; x++)
        {
            if (Map[y][x] == 'F')
            {
                isfire[y][x] = true;
                fire.push(Coord(y, x));
            }
            else if (Map[y][x] == 'J')
                start.y = y, start.x = x;
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
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> Map[i];

    return bfs();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int rtn = solve();
    if (rtn == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << rtn << '\n';
}