#include <bits/stdc++.h>

int n, m, t;
int map[100][100];
int cost[100][100][2]; // 0: non-blade, 1: blade
int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const int MAX = 0x3f3f3f3f;

struct node
{
    int r, c, time;
    bool blade;
    node(int r, int c, int time, bool blade) : r(r), c(c), time(time), blade(blade) {}
};

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < m;
}

void getinput()
{
    std::cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
}

int solve()
{
    auto comp = [](const node &a, const node &b)
    {
        return a.time > b.time;
    };
    std::priority_queue<node, std::vector<node>, decltype(comp)> pq(comp);

    std::memset(cost, 0x3f, sizeof(cost));

    pq.emplace(0, 0, 0, map[0][0] == 2);
    while (!pq.empty())
    {
        auto [r, c, cur_time, has_blade] = pq.top();
        pq.pop();

        if (cur_time > t)
            return -1;

        if (r == n - 1 && c == m - 1)
            return cur_time;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + d[i][0], nc = c + d[i][1];
            if (!isin(nr, nc))
                continue;
            bool n_blade = has_blade || (map[nr][nc] == 2);
            if (((map[nr][nc] != 1) || (n_blade)) && cur_time + 1 < cost[nr][nc][n_blade])
            {
                cost[nr][nc][n_blade] = cur_time + 1;
                pq.emplace(nr, nc, cur_time + 1, n_blade);
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    int result = solve();
    if (result == -1)
        std::cout << "Fail" << '\n';
    else
        std::cout << result << '\n';
}