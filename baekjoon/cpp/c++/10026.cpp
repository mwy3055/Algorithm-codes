#include <cstdio>
#include <queue>
using namespace std;
struct coord
{
    int y, x;
};

int n;
char map[100][101];
bool nvisit[100][100], dvisit[100][100];

inline bool isin(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}
inline bool similar(int i, int j, int y, int x)
{
    if (map[y][x] == 'R' || map[y][x] == 'G')
        return map[i][j] == 'R' || map[i][j] == 'G';
    else
        return map[i][j] == map[y][x];
}
void nbfs(int i, int j)
{
    queue<coord> q;
    int src[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, sy, sx;

    q.push({i, j});
    nvisit[i][j] = true;
    while (!q.empty())
    {
        coord &top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            sy = top.y + src[k][0], sx = top.x + src[k][1];
            if (isin(sy, sx) && map[sy][sx] == map[i][j] && !nvisit[sy][sx])
            {
                nvisit[sy][sx] = true;
                q.push({sy, sx});
            }
        }
    }
}
void dbfs(int i, int j)
{
    queue<coord> q;
    int src[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, sy, sx;

    q.push({i, j});
    dvisit[i][j] = true;
    while (!q.empty())
    {
        coord &top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            sy = top.y + src[k][0], sx = top.x + src[k][1];
            if (isin(sy, sx) && similar(sy, sx, i, j) && !dvisit[sy][sx])
            {
                dvisit[sy][sx] = true;
                q.push({sy, sx});
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);

    int ncount = 0, dcount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!nvisit[i][j])
            {
                nbfs(i, j);
                ncount++;
            }
            if (!dvisit[i][j])
            {
                dbfs(i, j);
                dcount++;
            }
        }
    }
    printf("%d %d", ncount, dcount);
}