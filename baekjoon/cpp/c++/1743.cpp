#include <bits/stdc++.h>

using coord = std::pair<int, int>;
bool drop[101][101], visit[101][101];
int n, m, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

bool isin(int r, int c)
{
    return 0 < r && r <= n && 0 < c && c <= m;
}

int bfs(int r, int c)
{
    std::queue<coord> q;
    visit[r][c] = true;
    q.push(coord(r, c));

    int size = 1;
    while (!q.empty())
    {
        auto top = q.front();
        auto &r = top.first, &c = top.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + src[i][0], nc = c + src[i][1];
            if (isin(nr, nc) && drop[nr][nc] && !visit[nr][nc])
            {
                visit[nr][nc] = true;
                q.push(coord(nr, nc));
                size++;
            }
        }
    }
    return size;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        std::cin >> r >> c;
        drop[r][c] = true;
    }

    int ans = 0;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            if (drop[r][c] && !visit[r][c])
            {
                ans = std::max(ans, bfs(r, c));
            }
        }
    }
    std::cout << ans << '\n';
}