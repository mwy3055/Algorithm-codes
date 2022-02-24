#include <bits/stdc++.h>
using namespace std;

int n, m;
char Map[1000][1001], visit[1000][1000][2]; //[y][x][0]: 부수고 온 경우, [y][x][1]: 부수지 않고 온 경우. 방문체크 주의!!
int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct Coord
{
    int y, x;
    bool flag;
    Coord(int y = 0, int x = 0, bool flag = false) : y(y), x(x), flag(flag) {}
    bool isin() const
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    bool operator==(const Coord &c) const
    {
        return this->y == c.y && this->x == c.x;
    }
    bool is_wall() const
    {
        return Map[y][x] == '1';
    }
};

void getinput()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Map[i][j];
}
int bfs()
{
    queue<Coord> q;

    Coord start(0, 0, true), end(n - 1, m - 1, true);
    visit[0][0][1] = true;
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
                Coord next(top.y + src[i][0], top.x + src[i][1], top.flag);
                if ((next.isin() && next.is_wall() && next.flag && !visit[next.y][next.x][0]) ||
                    (next.isin() && !next.is_wall() && !visit[next.y][next.x][next.flag]))
                {
                    if (next.is_wall())
                        next.flag = false;

                    q.push(next);
                    visit[next.y][next.x][next.flag] = true;
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