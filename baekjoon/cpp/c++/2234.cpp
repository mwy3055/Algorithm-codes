#include <bits/stdc++.h>

using pii = std::pair<int, int>;

// n: 가로. m: 세로
int n, m, map[50][50];
bool visit[50][50];

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
}

void init()
{
    std::memset(visit, false, sizeof(visit));
}

bool isin(int r, int c)
{
    return (0 <= r && r < m) && (0 <= c && c < n);
}

// (sr, sc)에서 bfs를 시작
int bfs(int sr, int sc)
{
    std::queue<pii> q;

    int count = 0;
    q.emplace(sr, sc);
    visit[sr][sc] = true;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        count++;

        // 방향
        for (int i = 0; i < 4; i++)
        {
            // 벽이 있으면
            if (map[r][c] & (1 << i))
                continue;
            int nr = r + dr[i], nc = c + dc[i];
            if (isin(nr, nc) && !visit[nr][nc])
            {
                q.emplace(nr, nc);
                visit[nr][nc] = true;
            }
        }
    }
    return count;
}

pii solve12()
{
    init();

    auto room = 0, max_room = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                max_room = std::max(max_room, bfs(i, j));
                room++;
            }
        }
    }
    return {room, max_room};
}

int solve3()
{
    int max_room = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (map[i][j] & (1 << k))
                {
                    // 이 벽을 제거해 보자
                    init();
                    map[i][j] -= (1 << k);
                    max_room = std::max(max_room, bfs(i, j));
                    map[i][j] += (1 << k);
                }
            }
        }
    }
    return max_room;
}

void solve()
{
    // 1, 2
    auto [ans1, ans2] = solve12();
    // 3
    auto ans3 = solve3();
    std::cout << ans1 << '\n'
              << ans2 << '\n'
              << ans3 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}