#include <iostream>
#include <queue>
using namespace std;
struct coord
{
    int y, x;
};

int n, m, ans = 0;
char map[50][50];

inline bool isin(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int i, int j)
{
    queue<coord> q;
    bool visit[50][50] = {false};
    int src[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    q.push({i, j});
    visit[i][j] = true;
    int d;
    for (d = 1; !q.empty(); d++)
    {
        int siz = q.size();
        while (siz--)
        {
            coord &top = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int sy = top.y + src[k][0], sx = top.x + src[k][1];
                if (isin(sy, sx) && map[sy][sx] == 'L' && !visit[sy][sx])
                {
                    visit[sy][sx] = true;
                    q.push({sy, sx});
                }
            }
        }
    }
    ans = max(d, ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 'L')
                bfs(i, j);

    cout << ans - 2;
}