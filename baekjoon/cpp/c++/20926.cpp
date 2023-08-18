#include <bits/stdc++.h>

using pii = std::pair<int, int>; // cost, dest
using pq_pii = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;

const int MAX = 500;
int w, h;
char map[MAX][MAX + 1];
int slip_time[MAX][MAX], total_time[MAX * MAX];
std::vector<pii> graph[MAX * MAX];
int d[][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

bool isin(int r, int c)
{
    return 0 <= r && r < h && 0 <= c && c < w;
}

int linearlize(int r, int c)
{
    return r * w + c;
}

void getinput()
{
    std::cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cin >> map[i][j];
            if ('0' <= map[i][j] && map[i][j] <= '9')
            {
                slip_time[i][j] = map[i][j] - '0';
            }
        }
    }
}

int find(char c)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == c)
                return linearlize(i, j);
        }
    }
    exit(-1);
}

pii slip(int dir, int cur)
{
    auto r = cur / w, c = cur % w, cost = 0;
    while (true)
    {
        auto nr = r + d[dir][0], nc = c + d[dir][1];
        if (!isin(nr, nc) || map[nr][nc] == 'H')
            return pii(-1, -1);
        else if (map[nr][nc] == 'R')
            break;
        else if (map[nr][nc] == 'E')
        {
            r = nr, c = nc;
            break;
        }
        r += d[dir][0], c += d[dir][1];
        cost += slip_time[r][c];
    }
    return pii(cost, linearlize(r, c));
}

char getmap(int cur)
{
    return map[cur / w][cur % w];
}

int solve()
{
    // dijkstra
    std::memset(total_time, 0x3f, sizeof(total_time));
    pq_pii pq;

    auto start = find('T');
    total_time[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (getmap(cur) == 'E')
            return cost;

        // slip (top, bottom, left, right)
        for (int dir = 0; dir < 4; dir++)
        {
            auto [ncost, next] = slip(dir, cur);
            if (next == cur || next == -1)
                continue;
            if (cost + ncost < total_time[next])
            {
                total_time[next] = cost + ncost;
                pq.emplace(cost + ncost, next);
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
    std::cout << solve() << '\n';
}