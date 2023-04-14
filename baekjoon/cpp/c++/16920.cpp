#include <bits/stdc++.h>

using coord = std::pair<int, int>;

int n, m, p;
int s[10];
char map[1000][1001];
std::vector<coord> castle[10];

const int INF = 0x3f3f3f3f;
int mdist[1000][1000], nearest[1000][1000];

int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void getinput()
{
    std::cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
    {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != '.' && map[i][j] != '#')
            {
                auto no = map[i][j] - '0';
                castle[no].emplace_back(i, j);
            }
        }
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

bool bfs(int player)
{
    std::queue<coord> q;
    for (auto &c : castle[player])
    {
        q.push(c);
        mdist[c.first][c.second] = 0;
        nearest[c.first][c.second] = player;
    }

    bool expanded = false;

    int dist = 1;
    while (!q.empty() && dist <= s[player])
    {
        int size = q.size();
        while (size--)
        {
            auto top = q.front();
            q.pop();

            for (auto &[dr, dc] : d)
            {
                int nr = top.first + dr, nc = top.second + dc;
                if (isin(nr, nc) && map[nr][nc] == '.' && mdist[nr][nc] > dist)
                {
                    expanded = true;
                    q.emplace(nr, nc);
                    map[nr][nc] = '0' + player;
                }
            }
        }
        dist++;
    }

    castle[player].clear();
    while (!q.empty())
    {
        castle[player].push_back(q.front());
        q.pop();
    }

    return expanded;
}

void solve()
{
    std::memset(mdist, 0x3f, sizeof(mdist));
    while (true)
    {
        bool expanded = false;
        for (int i = 1; i <= p; i++)
        {
            expanded |= bfs(i);
        }
        if (!expanded)
            break;
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count[map[i][j] - '0']++;
        }
    }

    for (int i = 1; i <= p; i++)
    {
        std::cout << count[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}