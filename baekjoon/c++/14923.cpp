#include <bits/stdc++.h>

int n, m, hx, hy, ex, ey;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int map[1001][1001];
bool visit[1001][1001][2];

struct node
{
    int x, y;
    bool magic;
    node(int x, int y, bool m) : x(x), y(y), magic(m) {}
};

int isin(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int solve()
{
    std::queue<node> q;

    visit[hx][hy][1] = true;
    q.push(node(hx, hy, true));
    int ans = 0;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            q.pop();

            auto &x = top.x, &y = top.y;
            bool &magic = top.magic;
            if (x == ex && y == ey)
                return ans;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (!isin(nx, ny) || visit[nx][ny][magic])
                    continue;
                if (!map[nx][ny])
                {
                    visit[nx][ny][magic] = true;
                    q.push(node(nx, ny, magic));
                }
                else if (map[nx][ny] && magic)
                {
                    visit[nx][ny][0] = true;
                    q.push(node(nx, ny, false));
                }
            }
        }
        ans++;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> hx >> hy >> ex >> ey;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    std::cout << solve();
}