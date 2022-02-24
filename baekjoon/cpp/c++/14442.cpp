#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char Map[1000][1001], visit[1000][1000][11]; // [y][x][k] : (y, x)에 오기까지 k번 벽을 부숨
int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct Coord
{
    int y, x, count;
    Coord(int y = 0, int x = 0, int count = 0) : y(y), x(x), count(count) {}
    bool operator==(const Coord &c) const
    {
        return this->y == c.y && this->x == c.x;
    }
};

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
bool iswall(int y, int x)
{
    return Map[y][x] == '1';
}

void getinput()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Map[i][j];
}
int bfs()
{
    queue<Coord> q;

    Coord start(0, 0, 0), end(n - 1, m - 1, 0);
    visit[0][0][0] = true;
    q.push(start);

    int cnt = 1;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            Coord top = q.front();
            q.pop();

            if (top == end)
                return cnt;

            for (int i = 0; i < 4; i++)
            {
                int ny = top.y + src[i][0], nx = top.x + src[i][1], count = top.count;
                if (isin(ny, nx) &&
                    ((iswall(ny, nx) && count < k && !visit[ny][nx][count + 1]) || !iswall(ny, nx) && !visit[ny][nx][count]))
                {
                    if (iswall(ny, nx))
                        count++;

                    q.push(Coord(ny, nx, count));
                    visit[ny][nx][count] = true;
                }
            }
        }
        cnt++;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    getinput();
    cout << bfs();
}