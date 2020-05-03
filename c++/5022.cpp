#include <bits/stdc++.h>
using namespace std;

struct coord
{
    int y, x;
    coord(int y = 0, int x = 0) : y(y), x(x) {}
    bool operator==(coord c) const
    {
        return (y == c.y) && (x == c.x);
    }
    bool operator!=(coord c) const
    {
        return !(*this == c);
    }
};
const int INF = 0x3f3f3f3f;
int n, m, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool visit[101][101];
coord track[101][101];

void init()
{
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            visit[i][j] = false;
}
bool isin(int y, int x)
{
    return 0 <= y && y <= m && 0 <= x && x <= n;
}
int bfs(coord &s, coord &e, coord &p1, coord &p2)
{
    queue<coord> q;
    coord finish(-1, -1);

    int rtn = 0;
    visit[s.y][s.x] = true;
    q.push(s);
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto &y = top.y, &x = top.x;
            q.pop();

            if (top == e)
            {
                finish = e;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int ny = y + src[i][0], nx = x + src[i][1];
                coord next(ny, nx);
                if (isin(ny, nx) && !visit[ny][nx] && next != p1 && next != p2)
                {
                    visit[ny][nx] = true;
                    track[ny][nx] = top;
                    q.push(next);
                }
            }
        }
        rtn++;
    }
    if (finish != e)
        return INF;

    init();
    auto &cur = finish;
    int ans = 0;
    while (cur != s)
    {
        visit[cur.y][cur.x] = true;
        cur = track[cur.y][cur.x];
        ans++;
    }
    visit[cur.y][cur.x] = true;
    return ans;
}
int solve(coord &p1, coord &p2, coord &q1, coord &q2) // connect p1->p2, then q1->q2
{
    init();
    int d1 = bfs(p1, p2, q1, q2), d2 = bfs(q1, q2, p1, p2);
    return min(d1 + d2, INF);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    coord a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y >> b1.x >> b1.y >> b2.x >> b2.y;

    int ans1 = solve(a1, a2, b1, b2); // A first, then B
    int ans2 = solve(b1, b2, a1, a2); // B first, then A
    if (ans1 == INF && ans2 == INF)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << min(ans1, ans2) << '\n';
}