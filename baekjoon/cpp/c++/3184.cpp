#include <iostream>
#include <queue>
using namespace std;

struct coord
{
    int y, x;
};

char map[250][250];
bool visit[250][250];
int sheep, wolf, r, c;

bool isin(int i, int j)
{
    return 0 <= i && i < r && 0 <= j && j < c;
}
void bfs(int &i, int &j)
{
    queue<coord> q;
    coord src[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int tsheep = 0, twolf = 0;

    q.push({i, j});
    visit[i][j] = true;
    while (!q.empty())
    {
        coord &top = q.front();
        q.pop();
        if (map[top.y][top.x] == 'o')
            tsheep++;
        else if (map[top.y][top.x] == 'v')
            twolf++;

        for (coord &c : src)
        {
            int sy = top.y + c.y, sx = top.x + c.x;
            if (isin(sy, sx) && map[sy][sx] != '#' && !visit[sy][sx])
            {
                q.push({sy, sx});
                visit[sy][sx] = true;
            }
        }
    }
    if (tsheep > twolf)
        wolf -= twolf;
    else
        sheep -= tsheep;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> map[i];
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'o')
                sheep++;
            else if (map[i][j] == 'v')
                wolf++;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] != '#' && !visit[i][j])
                bfs(i, j);
        }
    }
    cout << sheep << " " << wolf;
}