#include <bits/stdc++.h>
using namespace std;

class coord
{
public:
    int y, x;
    coord(int y, int x) : y(y), x(x) {}
    bool operator==(const coord &c)
    {
        return this->y == c.y && this->x == c.x;
    }
};

int n, Map[64][64];
bool visit[64][64];

inline bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool bfs()
{
    queue<coord> q;

    q.push(coord(0, 0));
    visit[0][0] = true;

    coord finish(n - 1, n - 1);
    while (!q.empty())
    {
        coord &top = q.front();
        q.pop();

        if (top == finish)
            return true;

        int sy = top.y + Map[top.y][top.x], sx = top.x;
        if (isin(sy, sx) && !visit[sy][sx])
        {
            q.push(coord(sy, sx));
            visit[sy][sx] = true;
        }

        sy = top.y, sx = top.x + Map[top.y][top.x];
        if (isin(sy, sx) && !visit[sy][sx])
        {
            q.push(coord(sy, sx));
            visit[sy][sx] = true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Map[i][j];

    cout << (bfs() ? "HaruHaru" : "Hing");
}