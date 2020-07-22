#include <bits/stdc++.h>

using pii = std::pair<int, int>;
int map[100][70], n, m, src[][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
bool visit[100][70];
std::vector<std::vector<pii>> tops;

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(int y, int x)
{
    std::queue<pii> q;
    std::vector<pii> curtops;

    visit[y][x] = true;
    q.push(pii(y, x));
    curtops.emplace_back(y, x);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        auto &y = top.first, &x = top.second;
        for (int i = 0; i < 8; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && !visit[ny][nx] && map[ny][nx] == map[y][x])
            {
                visit[ny][nx] = true;
                q.push(pii(ny, nx));
                curtops.emplace_back(ny, nx);
            }
        }
    }
    tops.push_back(curtops);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && map[i][j])
            {
                bfs(i, j);
            }
        }
    }

    int ans = 0;
    for (auto &top : tops)
    {
        bool ishigh = true;
        for (auto &cell : top)
        {
            auto &y = cell.first, &x = cell.second;
            for (int i = 0; i < 8; i++)
            {
                int ny = y + src[i][0], nx = x + src[i][1];
                if (isin(ny, nx) && map[ny][nx] > map[y][x])
                {
                    ishigh = false;
                    break;
                }
            }
        }
        if (ishigh)
            ans++;
    }
    std::cout << ans << '\n';
}