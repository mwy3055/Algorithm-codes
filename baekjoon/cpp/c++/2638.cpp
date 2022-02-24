#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct coord
{
    int y, x;
};

bool map[100][100];
int cnt[100][100], n, m;
inline bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool bfs(int &bef)
{
    bool visit[100][100] = {false};
    int src[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<coord> q;
    memset(cnt, 0, 100 * 100 * sizeof(int));

    q.push({0, 0});
    visit[0][0] = true;
    while (!q.empty())
    {
        coord &top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int sy = top.y + src[i][0], sx = top.x + src[i][1];
            if (isin(sy, sx))
            {
                if (map[sy][sx])
                    cnt[sy][sx]++;
                else if (!visit[sy][sx])
                { 
                    q.push({sy, sx});
                    visit[sy][sx] = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j])
            {
                if (2 <= cnt[i][j])
                    map[i][j] = false;
                else
                    count++;
            }
        }
    }
    if (count!=0)
    {
        bef = count;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0, bef = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j])
                bef++;
        }
    }

    do
    {
        cnt++;
    } while (bfs(bef));
    cout << cnt << '\n' << bef;
}