#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, m;
std::vector<pii> switches[100][100];
bool light[100][100]; // 불이 켜져 있는가?

bool visit[100][100];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < n;
}

/**
 * 갈 수 있는 방의 개수가 아니라
 * 불을 켤 수 있는 방의 개수를 세어야 한다.
 */
int solve()
{
    std::queue<pii> q;

    int ans = 1;
    light[0][0] = true;
    q.emplace(0, 0);
    visit[0][0] = true;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        int r = top.first, c = top.second;
        // std::cout << r << ' ' << c << '\n';

        for (auto &[sr, sc] : switches[r][c])
        {
            if (!light[sr][sc])
            {
                light[sr][sc] = true;
                ans++;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = sr + dr[i], nc = sc + dc[i];
                if (isin(nr, nc) && visit[nr][nc] && !visit[sr][sc])
                {
                    visit[sr][sc] = true;
                    q.emplace(sr, sc);
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (isin(nr, nc) && !visit[nr][nc] && light[nr][nc])
            {
                visit[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        switches[--x][--y].emplace_back(--a, --b);
    }

    std::cout << solve() << '\n';
}